#!/usr/bin/env python3
"""Move sources from their local partial views of a game struct onto the shared one.

The sources declare the game's structs locally, each only the fields it touches (see
structviews.py). Once a struct is declared in include/, this rewrites a source to use it:

  * finds the file's local struct types that are views of the shared struct (their fields sit at
    the offsets, sizes and bit positions of the shared struct's fields);
  * rewrites every member access through such a view, by type, to the shared struct's member
    path (`self->f60.lo` -> `self->flags60.bits.lo`), following nested members and arrays;
  * replaces the view type by the shared one (a view with fields past the shared struct keeps its
    own type, rebuilt as `{ Shared base; <its extension> }`, and its base accesses gain `base.`);
  * adds the header's #include.

Each source is preprocessed with mwcc (-E) and parsed with pycparser, so types come from the real
headers. Nothing is kept unless the rewritten source still compiles to the same bytes:

    python tools/structconv.py --header game/actor.h --struct Actor --analyze FILES...
    python tools/structconv.py --header game/actor.h --struct Actor FILES...     # stage + verify
    python tools/structconv.py --apply                                           # write the plan

FILES may be globs or @listfile. The plan (sources that matched) goes to build/structconv_plan.json,
the per-file reasons to build/structconv_report.txt.
"""
import argparse
import collections
import glob
import json
import os
import re
import shutil
import subprocess
import sys

from pycparser import c_ast, c_generator, c_parser

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from structviews import SIZES  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MWCC = os.path.join(ROOT, 'tools', 'mwccarm', '3.0_patch4', 'mwccarm.exe')
LICENSE = os.path.join(ROOT, 'tools', 'mwccarm', 'license.dat')
PLAN = os.path.join(ROOT, 'build', 'structconv_plan.json')
REPORT = os.path.join(ROOT, 'build', 'structconv_report.txt')
GEN = c_generator.CGenerator()


class Skip(Exception):
    pass


# ---------------------------------------------------------------- preprocessing and parsing

def preprocess(path):
    env = dict(os.environ, LM_LICENSE_FILE=LICENSE)
    r = subprocess.run([MWCC, '-E', '-lang', 'c99', '-enum', 'int', '-char', 'signed', '-gccext,on',
                        '-i', os.path.join(ROOT, 'include'), path],
                       capture_output=True, text=True, env=env, cwd=ROOT)
    if r.returncode != 0 or not r.stdout.strip():
        raise Skip('preprocess failed')
    out = []
    for line in r.stdout.split('\n'):
        m = re.match(r'#line\s+(\d+)(?:\s+"((?:[^"\\]|\\.)*)")?', line)
        if m:
            f = m.group(2)
            out.append('#line %s%s' % (m.group(1), (' "%s"' % f) if f is not None else ''))
            continue
        out.append(line)
    text = '\n'.join(out)
    text = re.sub(r'__attribute__\s*\(\((?:[^()]|\([^()]*\))*\)\)', '', text)
    return text


def norm(f):
    return os.path.normcase(os.path.abspath(f.replace('\\\\', '\\'))) if f else f


def parse(path):
    text = preprocess(path)
    if re.search(r'\basm\b|\b__asm\b', text):
        raise Skip('asm')
    try:
        return c_parser.CParser().parse(text, filename=path)
    except Exception as e:  # pycparser errors
        raise Skip('parse: %s' % str(e)[:80])


# ---------------------------------------------------------------- types

class Types:
    """Typedefs, tags and layout of one translation unit."""

    def __init__(self, ast):
        self.typedefs, self.tags, self.funcs, self.globals, self.enums = {}, {}, {}, {}, {}
        for ext in ast.ext:
            if isinstance(ext, c_ast.Typedef):
                self.typedefs[ext.name] = ext
                self._tags(ext.type)
            elif isinstance(ext, c_ast.Decl):
                self._tags(ext.type)
                if ext.name:
                    if isinstance(ext.type, c_ast.FuncDecl):
                        self.funcs[ext.name] = ext.type
                    else:
                        self.globals[ext.name] = ext.type
            elif isinstance(ext, c_ast.FuncDef):
                self.funcs[ext.decl.name] = ext.decl.type
                self._tags(ext.decl.type)

    def const(self, e):
        """Value of an integer constant expression (Skip when it is not one)."""
        if isinstance(e, c_ast.Constant):
            v = e.value
            if e.type == 'char':
                s = v[1:-1]
                if len(s) == 1:
                    return ord(s)
                if s[1] == 'x':
                    return int(s[2:], 16)
                if s[1].isdigit():
                    return int(s[1:], 8)
                return {'n': 10, 't': 9, 'r': 13, '\\': 92, "'": 39, '"': 34}.get(s[1], 0)
            v = v.rstrip('uUlL')
            try:
                return int(v, 0) if not re.match(r'^0\d', v) else int(v, 8)
            except ValueError:
                raise Skip('constant %s' % e.value)
        if isinstance(e, c_ast.BinaryOp):
            a, b = self.const(e.left), self.const(e.right)
            ops = {'+': a + b, '-': a - b, '*': a * b, '<<': a << b if b >= 0 else 0,
                   '>>': a >> b if b >= 0 else 0, '&': a & b, '|': a | b, '^': a ^ b,
                   '==': int(a == b), '!=': int(a != b), '<': int(a < b), '>': int(a > b),
                   '<=': int(a <= b), '>=': int(a >= b), '&&': int(bool(a and b)), '||': int(bool(a or b))}
            if e.op in ('/', '%'):
                if b == 0:
                    raise Skip('division by zero')
                q = abs(a) // abs(b) * (1 if (a >= 0) == (b >= 0) else -1)
                return q if e.op == '/' else a - q * b
            if e.op in ops:
                return ops[e.op]
            raise Skip('operator %s' % e.op)
        if isinstance(e, c_ast.UnaryOp):
            if e.op == 'sizeof':
                t = e.expr.type if isinstance(e.expr, c_ast.Typename) else None
                if t is None:
                    raise Skip('sizeof expression')
                return self.size_align(t)[0]
            v = self.const(e.expr)
            return {'-': -v, '+': v, '~': ~v, '!': int(not v)}.get(e.op, v)
        if isinstance(e, c_ast.Cast):
            return self.const(e.expr)
        if isinstance(e, c_ast.TernaryOp):
            return self.const(e.iftrue) if self.const(e.cond) else self.const(e.iffalse)
        if isinstance(e, c_ast.ID) and e.name in self.enums:
            return self.enums[e.name]
        raise Skip('not a constant')

    def _tags(self, t):
        for node in walk_types(t):
            if isinstance(node, (c_ast.Struct, c_ast.Union)) and node.name and node.decls is not None:
                self.tags[('u' if isinstance(node, c_ast.Union) else 's') + node.name] = node
            elif isinstance(node, c_ast.Enum) and node.values is not None:
                v = -1
                for en in node.values.enumerators:
                    try:
                        v = self.const(en.value) if en.value is not None else v + 1
                    except Skip:
                        v = v + 1
                    self.enums[en.name] = v

    def strip(self, t):
        """Follow typedefs of a TypeDecl down to the first pointer/array/aggregate/scalar."""
        seen = 0
        while isinstance(t, c_ast.TypeDecl) and isinstance(t.type, c_ast.IdentifierType):
            name = ' '.join(n for n in t.type.names if n not in ('const', 'volatile'))
            td = self.typedefs.get(name)
            if td is None or seen > 20:
                return t
            t = td.type
            seen += 1
        if isinstance(t, c_ast.Typename):
            return self.strip(t.type)
        return t

    def agg(self, t):
        """The complete struct/union node of a value type, or None."""
        t = self.strip(t)
        if isinstance(t, c_ast.TypeDecl):
            t = t.type
        if isinstance(t, (c_ast.Struct, c_ast.Union)):
            if t.decls is None:
                t = self.tags.get(('u' if isinstance(t, c_ast.Union) else 's') + (t.name or ''), t)
            return t if t.decls is not None else None
        return None

    def pointee(self, t):
        t = self.strip(t)
        if isinstance(t, (c_ast.PtrDecl, c_ast.ArrayDecl)):
            return t.type
        return None

    def scalar_name(self, t):
        t = self.strip(t)
        if isinstance(t, c_ast.TypeDecl):
            if isinstance(t.type, c_ast.IdentifierType):
                return ' '.join(n for n in t.type.names if n not in ('const', 'volatile'))
            if isinstance(t.type, c_ast.Enum):
                return 'enum'
        return None

    def kind(self, t):
        t = self.strip(t)
        if isinstance(t, c_ast.PtrDecl):
            return 'ptr'
        if isinstance(t, c_ast.ArrayDecl):
            return 'array'
        if isinstance(t, c_ast.FuncDecl):
            return 'func'
        if self.agg(t) is not None:
            return 'union' if isinstance(self.agg(t), c_ast.Union) else 'struct'
        return 'scalar'

    def size_align(self, t):
        t = self.strip(t)
        k = self.kind(t)
        if k == 'ptr':
            return 4, 4
        if k == 'array':
            s, a = self.size_align(t.type)
            return s * (self.const(t.dim) if t.dim is not None else 0), a
        if k in ('struct', 'union'):
            _, size, align = self.fields(self.agg(t))
            return size, align
        name = self.scalar_name(t)
        if name == 'enum':
            return 4, 4
        s = SIZES.get(name)
        if s is None:
            raise Skip('size of %s' % name)
        return s, s

    def fields(self, node):
        """([(off, bitpos, bitsize, name, type)], size, align); anonymous members inline."""
        union = isinstance(node, c_ast.Union)
        out, off, align, unit = [], 0, 1, None
        for d in node.decls or []:
            s, a = self.size_align(d.type)
            align = max(align, a)
            if d.bitsize is not None:
                bits = self.const(d.bitsize)
                if union:
                    out.append((0, 0, bits, d.name, d.type))
                    off = max(off, s)
                    continue
                if unit and unit[1] == s and unit[2] + bits <= s * 8:
                    out.append((unit[0], unit[2], bits, d.name, d.type))
                    unit = (unit[0], s, unit[2] + bits)
                    continue
                start = (off + a - 1) // a * a
                out.append((start, 0, bits, d.name, d.type))
                unit = (start, s, bits)
                off = start + s
                continue
            unit = None
            start = 0 if union else (off + a - 1) // a * a
            out.append((start, None, None, d.name, d.type))
            off = max(off, start + s) if union else start + s
        size = (off + align - 1) // align * align
        return out, size, align

    def member(self, node, name):
        """(off, bitpos, bitsize, type) of a member, looking into anonymous members."""
        for off, bp, bs, n, t in self.fields(node)[0]:
            if n == name:
                return off, bp, bs, t
            if n is None and self.agg(t) is not None:
                r = self.member(self.agg(t), name)
                if r:
                    return (off + r[0],) + r[1:]
        return None

    def cls(self, t):
        """Scalar class: 'P' pointer, 'U'/'I' unsigned/signed integer, 'F' float, 'E' enum."""
        k = self.kind(t)
        if k == 'ptr':
            return 'P'
        name = self.scalar_name(t)
        if name == 'enum':
            return 'I'
        if name in ('float', 'double'):
            return 'F'
        if name and (name.startswith('unsigned') or name == '_Bool'):
            return 'U'
        if name == 'char':
            return 'I'  # -char signed
        return 'I'

    def leaves(self, t, base=0):
        """[(off, bitpos, bitsize, size, class)] of a type, aggregates flattened."""
        k = self.kind(t)
        if k in ('struct', 'union'):
            out = []
            for off, bp, bs, n, ft in self.fields(self.agg(t))[0]:
                if bs is not None:
                    out.append((base + off, bp, bs, self.size_align(ft)[0], self.cls(ft)))
                else:
                    out += self.leaves(ft, base + off)
            return out
        if k == 'array':
            s, _ = self.size_align(t.type)
            n = self.const(self.strip(t).dim) if self.strip(t).dim is not None else 0
            out = []
            for i in range(n):
                out += self.leaves(self.strip(t).type, base + i * s)
            return out
        return [(base, None, None, self.size_align(t)[0], self.cls(t))]

    def spell(self, t):
        """A type as it is written in a cast: no declarator name."""
        import copy
        t = copy.deepcopy(t)
        for n in walk_types(t):
            if isinstance(n, c_ast.TypeDecl):
                n.declname = None
        try:
            return GEN.visit(c_ast.Typename(None, [], None, t)).strip()
        except Exception:
            return '?'


def walk_types(t):
    stack = [t]
    while stack:
        n = stack.pop()
        if n is None:
            continue
        yield n
        if isinstance(n, (c_ast.TypeDecl, c_ast.PtrDecl, c_ast.ArrayDecl, c_ast.Typename)):
            stack.append(n.type)
        elif isinstance(n, c_ast.FuncDecl):
            stack.append(n.type)
            if n.args:
                stack += [p.type for p in n.args.params if hasattr(p, 'type')]
        elif isinstance(n, (c_ast.Struct, c_ast.Union)):
            stack += [d.type for d in n.decls or []]


# ---------------------------------------------------------------- the shared struct

class Canon:
    """Every member of the shared struct (and of its nested aggregates), by path."""

    def __init__(self, types, name):
        td = types.typedefs.get(name)
        node = types.agg(td.type) if td else types.tags.get('s' + name)
        if node is None:
            raise SystemExit('shared struct %s not found' % name)
        self.T, self.node = types, node
        self.size = types.fields(node)[1]
        self.nodes = []  # (off, bp, bs, type, path)
        self._collect(node, 0, '')

    def _collect(self, agg, base, path):
        for off, bp, bs, n, t in self.T.fields(agg)[0]:
            p = (path + '.' if path and n else path) + (n or '')
            self.nodes.append((base + off, bp, bs, t, p))
            if bs is None and self.T.agg(t) is not None:
                self._collect(self.T.agg(t), base + off, p)
            elif bs is None and self.T.kind(t) == 'array':
                et = self.T.strip(t).type
                if self.T.agg(et) is not None:
                    # members of an element: their own frame `p[]`, offsets from the element
                    self._collect(self.T.agg(et), 0, p + '[]')


# ---------------------------------------------------------------- matching

def compatible(VT, vt, CT, ct):
    """0 exact, 1 compatible pointer/int, None incompatible (view type vt vs canonical ct)."""
    vk, ck = VT.kind(vt), CT.kind(ct)
    try:
        vs, cs = VT.size_align(vt)[0], CT.size_align(ct)[0]
    except Skip:
        return None
    if vs != cs:
        return None
    if vk in ('struct', 'union') or ck in ('struct', 'union') or vk == 'array' or ck == 'array':
        if vk == 'array' and ck == 'array':
            ve, ce = VT.strip(vt).type, CT.strip(ct).type
            r = compatible(VT, ve, CT, ce)
            return r
        if vk not in ('struct', 'union', 'array') or ck not in ('struct', 'union', 'array'):
            return None
        cl = {(o, bp, bs): (s, c) for o, bp, bs, s, c in CT.leaves(ct)}
        worst = 0
        for o, bp, bs, s, c in VT.leaves(vt):
            m = cl.get((o, bp, bs))
            if m is None or m[0] != s:
                return None
            if m[1] != c:
                if {m[1], c} <= {'P', 'I', 'U'} and 'P' in (m[1], c):
                    worst = max(worst, 1)
                elif {m[1], c} == {'I', 'U'}:
                    worst = max(worst, 2)
                else:
                    return None
        # an aggregate must not be matched to a smaller-grained canonical one it cannot express
        return worst
    vc, cc = VT.cls(vt), CT.cls(ct)
    if vc == cc:
        return 0
    if 'P' in (vc, cc) and {vc, cc} <= {'P', 'I', 'U'}:
        # a number stored where the shared struct keeps a function is another object's field
        for T, t in ((CT, ct), (VT, vt)):
            if T.kind(t) == 'ptr' and isinstance(T.strip(T.strip(t).type), c_ast.FuncDecl):
                return None
        return 1
    if {vc, cc} == {'I', 'U'}:
        return 2  # signedness differs: only a store-only use keeps the code; the build decides
    return None


def in_frame(path, frame):
    """Is a canonical member path directly inside `frame` ('' = the struct, 'x[]' = an element)?"""
    if frame:
        return path.startswith(frame + '.') and '[]' not in path[len(frame) + 1:]
    return '[]' not in path


def pick(canon, frame, off, bp, bs, VT, vt, parent=''):
    """Best canonical (path, type, level) for a view member at `off` in `frame`, strictly inside
    the canonical member `parent` (the one its enclosing view member was matched to)."""
    best = None
    vleaves = None
    for co, cbp, cbs, ct, cp in canon.nodes:
        if not in_frame(cp, frame):
            continue
        if parent and not cp.startswith(parent + '.'):
            continue
        rel = cp[len(frame) + 1:] if frame else cp
        if co != off or cbp != bp or cbs != bs or not rel:
            continue
        lvl = compatible(VT, vt, canon.T, ct)
        if lvl is None:
            continue
        # prefer exact, then the same set of leaves (not a union around them), then shallowest
        same = 0
        if VT.kind(vt) in ('struct', 'union'):
            key5 = lambda x: (x[0], -1 if x[1] is None else x[1], -1 if x[2] is None else x[2], x[3], x[4])
            if vleaves is None:
                vleaves = sorted(VT.leaves(vt), key=key5)
            same = 0 if sorted(canon.T.leaves(ct), key=key5) == vleaves else 1
        key = (lvl, same, rel.count('.'))
        if best is None or key < best[0]:
            best = (key, cp, ct, lvl)
    if best:
        return best[1], best[2], best[3]
    # a scalar view member inside a canonical array of that scalar: index it
    if bs is None and VT.kind(vt) == 'scalar':
        for co, cbp, cbs, ct, cp in canon.nodes:
            if not in_frame(cp, frame):
                continue
            if canon.T.kind(ct) != 'array' or cbs is not None:
                continue
            et = canon.T.strip(ct).type
            es = canon.T.size_align(et)[0]
            n = canon.T.size_align(ct)[0] // es if es else 0
            if co <= off < co + es * n and (off - co) % es == 0 and compatible(VT, vt, canon.T, et) == 0:
                return '%s[%d]' % (cp, (off - co) // es), et, 0
    return None


# ---------------------------------------------------------------- one source

class Conv:
    def __init__(self, path, canon_name, header):
        self.path, self.canon_name, self.header = path, canon_name, header
        self.ast = parse(path)
        self.T = Types(self.ast)
        self.canon = Canon(self.T, canon_name) if canon_name in self.T.typedefs else None
        self.src = open(path, encoding='utf-8').read()

    def local_views(self, canon, min_hits=3, lenient=False):
        """Struct types defined in this source that are views of the shared struct:
        [(struct node, typedef names, size, hits, misses)]; misses = [(off, bp, bs, name, type)]."""
        out = []
        for ext in self.ast.ext:
            for t in ([ext.type] if isinstance(ext, (c_ast.Typedef, c_ast.Decl)) else []):
                if ext.coord is None or norm(ext.coord.file) != norm(self.path):
                    continue
                node = self.T.agg(t) if isinstance(ext, c_ast.Typedef) else None
                if node is None:
                    for n in walk_types(t):
                        if isinstance(n, c_ast.Struct) and n.decls is not None:
                            node = n
                            break
                if node is None or not isinstance(node, c_ast.Struct) or any(v[0] is node for v in out):
                    continue
                if isinstance(ext, c_ast.Decl) and not isinstance(ext.type, c_ast.Struct) and ext.name:
                    continue  # a variable, not a type definition
                try:
                    fields, size, _ = self.T.fields(node)
                except Skip:
                    continue
                if size < 0x40:
                    continue
                hits, misses = 0, []
                for off, bp, bs, n, ft in fields:
                    if n is None or re.match(r'_?(pad|unk|reserved|padding)', n, re.I) and bs is None:
                        continue
                    if off >= canon.size:
                        continue
                    if pick(canon, '', off, bp, bs, self.T, ft) is not None:
                        hits += 1
                    else:
                        misses.append((off, bp, bs, n, ft))
                deep = sum(1 for off, bp, bs, n, ft in fields
                           if n and 0x60 <= off < canon.size and not re.match(r'_?(pad|unk|reserved|padding)', n, re.I))
                if hits >= min_hits and deep >= 2 and (lenient or not misses):
                    names = [ext.name] if isinstance(ext, c_ast.Typedef) else []
                    out.append((node, names, size, hits, misses))
        return out


INT_T = c_ast.TypeDecl(None, [], None, c_ast.IdentifierType(['int']))


class Rewriter:
    """Rewrite one source's accesses through its views of the shared struct."""

    def __init__(self, cv, canon, views):
        self.cv, self.T, self.canon = cv, cv.T, canon
        self.views = {id(v[0]): v for v in views}
        self.ext = {id(v[0]) for v in views if v[2] > canon.size}
        self.scopes = [dict(self.T.globals)]
        self.anchor = {}      # id(expr) -> (frame, off, canon path, canon type)
        self.edits = []       # (line, col, old, new, kind)
        self.parents = {}

    # -- scopes
    def lookup(self, name):
        for s in reversed(self.scopes):
            if name in s:
                return s[name]
        f = self.T.funcs.get(name)
        return f

    # -- expression types (None when unknown)
    def typeof(self, e):
        T = self.T
        if isinstance(e, c_ast.ID):
            return self.lookup(e.name)
        if isinstance(e, c_ast.Cast):
            return e.to_type.type
        if isinstance(e, c_ast.Constant):
            return INT_T
        if isinstance(e, c_ast.StructRef):
            bt = self.typeof(e.name)
            if bt is None:
                return None
            agg = T.agg(T.pointee(bt)) if e.type == '->' else T.agg(bt)
            if agg is None:
                return None
            m = T.member(agg, e.field.name)
            return m[3] if m else None
        if isinstance(e, c_ast.ArrayRef):
            bt = self.typeof(e.name)
            return T.pointee(bt) if bt is not None else None
        if isinstance(e, c_ast.UnaryOp):
            t = self.typeof(e.expr) if e.op != 'sizeof' else None
            if e.op == '*':
                return T.pointee(t) if t is not None else None
            if e.op == '&':
                return c_ast.PtrDecl([], t) if t is not None else None
            if e.op in ('++', '--', 'p++', 'p--'):
                return t
            return INT_T
        if isinstance(e, c_ast.BinaryOp):
            if e.op in ('+', '-'):
                lt, rt = self.typeof(e.left), self.typeof(e.right)
                for t in (lt, rt):
                    if t is not None and T.kind(t) in ('ptr', 'array'):
                        if T.kind(t) == 'array':
                            return c_ast.PtrDecl([], T.strip(t).type)
                        if e.op == '-' and lt is not None and rt is not None and \
                                T.kind(lt) == 'ptr' and T.kind(rt) == 'ptr':
                            return INT_T
                        return t
                return lt
            return INT_T
        if isinstance(e, c_ast.TernaryOp):
            return self.typeof(e.iftrue)
        if isinstance(e, c_ast.Assignment):
            return self.typeof(e.lvalue)
        if isinstance(e, c_ast.FuncCall):
            ft = self.typeof(e.name)
            if ft is None:
                return None
            ft = T.strip(ft)
            if isinstance(ft, c_ast.PtrDecl):
                ft = T.strip(ft.type)
            return ft.type if isinstance(ft, c_ast.FuncDecl) else None
        if isinstance(e, c_ast.ExprList):
            return self.typeof(e.exprs[-1])
        return None

    # -- the walk
    def run(self):
        for ext in self.cv.ast.ext:
            if isinstance(ext, c_ast.FuncDef):
                if ext.coord is None or norm(ext.coord.file) != norm(self.cv.path):
                    continue
                self.scopes.append({})
                fd = ext.decl.type
                if fd.args:
                    for p in fd.args.params:
                        if isinstance(p, c_ast.Decl) and p.name:
                            self.scopes[-1][p.name] = p.type
                for d in ext.param_decls or []:
                    self.scopes[-1][d.name] = d.type
                self.walk(ext.body, ext)
                self.scopes.pop()
            elif isinstance(ext, c_ast.Decl) and ext.init is not None:
                if ext.coord is not None and norm(ext.coord.file) == norm(self.cv.path):
                    self.walk(ext.init, ext)

    def walk(self, n, parent):
        if n is None:
            return
        self.parents[id(n)] = parent
        if isinstance(n, (c_ast.Compound, c_ast.For)):
            self.scopes.append({})
            for c in n:
                self.walk(c, n)
            self.scopes.pop()
            return
        if isinstance(n, c_ast.Decl):
            if n.init is not None:
                self.walk(n.init, n)
            if n.name:
                self.scopes[-1][n.name] = n.type
            return
        if isinstance(n, c_ast.StructRef):
            self.walk(n.name, n)
            self.structref(n)
            return
        if isinstance(n, c_ast.ArrayRef):
            self.walk(n.name, n)
            self.walk(n.subscript, n)
            self.arrayref(n)
            return
        if isinstance(n, c_ast.UnaryOp) and n.op == 'sizeof':
            t = n.expr.type if isinstance(n.expr, c_ast.Typename) else None
            if t is not None and self.is_view_type(t):
                raise Skip('sizeof of a view')
        for c in n:
            self.walk(c, n)

    def is_view_type(self, t):
        a = self.T.agg(t)
        return a is not None and id(a) in self.views

    def structref(self, n):
        T = self.T
        bt = self.typeof(n.name)
        if bt is None:
            if self.anchor.get(id(n.name)) is None:
                return
        base = self.anchor.get(id(n.name)) if n.type == '.' else None
        if base is not None:
            frame, off0, ppath, ptype = base
            vagg = T.agg(self.typeof(n.name)) if self.typeof(n.name) is not None else None
            root_ext = False
        else:
            if bt is None:
                return
            vagg = T.agg(T.pointee(bt)) if n.type == '->' else T.agg(bt)
            if vagg is None or id(vagg) not in self.views:
                return
            frame, off0, ppath = '', 0, ''
            root_ext = id(vagg) in self.ext
        if vagg is None:
            raise Skip('member of an unknown aggregate at line %d' % n.coord.line)
        m = T.member(vagg, n.field.name)
        if m is None:
            raise Skip('member %s not found' % n.field.name)
        moff, bp, bs, mt = m
        off = off0 + moff
        if base is None and root_ext and off >= self.canon.size:
            return  # the view's own extension: unchanged
        r = pick(self.canon, frame, off, bp, bs, T, mt, ppath if base is not None else '')
        how = None
        if r is None and T.kind(mt) == 'array' and bs is None:
            r = self.decay_target(frame, off)
            how = 'decay'
        if r is None:
            raise Skip('no counterpart for %s (0x%x, %s) line %d' % (n.field.name, off, T.spell(mt), n.coord.line))
        cpath, ctype, lvl = r
        rel = cpath[len(ppath) + 1:] if ppath else (cpath[len(frame) + 1:] if frame else cpath)
        if base is None and root_ext:
            rel = 'base.' + rel
        if how == 'decay':
            parent = self.parents.get(id(n))
            if isinstance(parent, (c_ast.ArrayRef, c_ast.StructRef)) or \
                    (isinstance(parent, c_ast.UnaryOp) and parent.op in ('sizeof', '&')):
                raise Skip('array %s used as an array at line %d' % (n.field.name, n.coord.line))
            if not isinstance(n.name, c_ast.ID):
                raise Skip('decayed array through a complex base at line %d' % n.coord.line)
            self.edits.append((n.field.coord.line, n.field.coord.column, n.field.name, rel, 'amp:' + n.name.name, None))
        else:
            cast = self.cast_for(n, mt, ctype)
            self.edits.append((n.field.coord.line, n.field.coord.column, n.field.name, rel, 'member', cast))
        self.anchor[id(n)] = (frame, off, cpath, ctype)

    def context(self, n):
        p = self.parents.get(id(n))
        if isinstance(p, c_ast.StructRef) and p.name is n:
            return 'member' if p.type == '.' else 'deref'
        if isinstance(p, c_ast.ArrayRef) and p.name is n:
            return 'index'
        if isinstance(p, c_ast.UnaryOp):
            return {'&': 'addr', '++': 'mod', '--': 'mod', 'p++': 'mod', 'p--': 'mod',
                    '*': 'deref', 'sizeof': 'sizeof'}.get(p.op, 'rvalue')
        if isinstance(p, c_ast.Assignment) and p.lvalue is n:
            return 'assign' if p.op == '=' else 'mod'
        if isinstance(p, c_ast.FuncCall) and p.name is n:
            return 'call'
        if isinstance(p, c_ast.BinaryOp) and p.op in ('+', '-'):
            return 'arith'
        return 'rvalue'

    def cast_for(self, n, mt, ct):
        r = self._cast_for(n, mt, ct)
        if r and '{' in r[1]:
            raise Skip('cast to an anonymous type at line %d' % n.coord.line)
        return r

    def _cast_for(self, n, mt, ct):
        """How to keep the view's own type where the shared member is declared differently:
        None, or (mode, spelled view type) with mode value / addr / copy."""
        T, CT = self.T, self.canon.T
        vs, cs = T.spell(T.strip(mt)), CT.spell(CT.strip(ct))
        if vs == cs:
            return None
        vk, ck = T.kind(mt), CT.kind(ct)
        if vk == ck == 'scalar' and T.cls(mt) == CT.cls(ct) and \
                T.size_align(mt)[0] == CT.size_align(ct)[0]:
            return None  # int / long / a typedef of either: the same code
        ctx = self.context(n)
        line = n.coord.line
        if vk in ('struct', 'union') or ck in ('struct', 'union'):
            if ctx == 'member':
                return None
            if ctx == 'addr':
                return ('addr', T.spell(mt))
            if ctx in ('assign', 'rvalue', 'mod'):
                return ('copy', T.spell(mt))
            raise Skip('aggregate of another type used as %s at line %d' % (ctx, line))
        if vk == 'array' or ck == 'array':
            if vk == ck and T.spell(T.strip(mt).type) == CT.spell(CT.strip(ct).type):
                return None
            raise Skip('array of another type at line %d' % line)
        if vk == 'ptr' and ck == 'ptr':
            if cs == 'void *' and ctx not in ('deref', 'arith', 'call', 'index'):
                return None
            if vs == 'void *' and ctx not in ('arith',):
                return None
            if cs.startswith('void (*)(') and ctx in ('assign', 'rvalue'):
                return None
            if ctx in ('addr', 'mod', 'assign'):
                raise Skip('pointer of another type used as %s at line %d' % (ctx, line))
            return ('value', T.spell(mt))
        if ctx == 'assign':
            return None
        if ctx in ('addr', 'mod'):
            raise Skip('%s of another type used as %s at line %d' % (vs, ctx, line))
        return ('value', T.spell(mt))

    def decay_target(self, frame, off):
        """For a view array only used as an address: the canonical member at that offset."""
        best = None
        for co, cbp, cbs, ct, cp in self.canon.nodes:
            if co == off and cbs is None and in_frame(cp, frame):
                if best is None or cp.count('.') < best[0].count('.'):
                    best = (cp, ct, 1)
        return best

    def arrayref(self, n):
        a = self.anchor.get(id(n.name))
        if a is None:
            return
        frame, off, cpath, ctype = a
        if self.canon.T.kind(ctype) != 'array':
            raise Skip('subscript of a non-array member at line %d' % n.coord.line)
        et = self.canon.T.strip(ctype).type
        if self.canon.T.agg(et) is not None:
            self.anchor[id(n)] = (cpath + '[]', 0, cpath + '[]', et)


def chain_start(text, i):
    """Start of the postfix expression (`a->b[i].c`, `f(x)->y`, `((T *)p)->z`) that ends at the
    member access whose `->`/`.` is at text[i]."""
    j = i
    while j > 0:
        k = j - 1
        while k >= 0 and text[k] in ' \t':
            k -= 1
        if k < 0:
            break
        c = text[k]
        if c.isalnum() or c == '_':
            while k >= 0 and (text[k].isalnum() or text[k] == '_'):
                k -= 1
            j = k + 1
            k2 = k
            while k2 >= 0 and text[k2] in ' \t':
                k2 -= 1
            if k2 >= 1 and text[k2 - 1:k2 + 1] == '->':
                j = k2 - 1
                continue
            if k2 >= 0 and text[k2] == '.' and not (k2 >= 1 and text[k2 - 1].isdigit()):
                j = k2
                continue
            break
        if c in ')]':
            depth, k2 = 0, k
            while k2 >= 0:
                if text[k2] in ')]':
                    depth += 1
                elif text[k2] in '([':
                    depth -= 1
                    if depth == 0:
                        break
                k2 -= 1
            if k2 < 0:
                raise Skip('unbalanced expression')
            j = k2
            k3 = k2 - 1
            while k3 >= 0 and text[k3] in ' \t':
                k3 -= 1
            if k3 >= 0 and (text[k3].isalnum() or text[k3] == '_' or text[k3] in ')]'):
                continue
            if k3 >= 1 and text[k3 - 1:k3 + 1] == '->':
                j = k3 - 1
                continue
            break
        break
    return j


def apply_edits(src, edits):
    """Apply member-name edits (and the casts that keep a view's type) located by line and by
    order of appearance on the line."""
    lines = src.split('\n')
    by_line = collections.defaultdict(list)
    for e in edits:
        by_line[e[0]].append(e)
    for ln, es in by_line.items():
        es.sort(key=lambda e: e[1])
        text = lines[ln - 1]
        occ = {}
        for e in es:
            occ.setdefault(e[2], []).append(e)
        reps, ins = [], []
        for name, group in occ.items():
            found = [m for m in re.finditer(r'(\b\w+\s*)?(->|\.)\s*(%s)\b' % re.escape(name), text)]
            if len(found) != len(group):
                # other objects' members of the same name share the line: place by column
                bycol = {m.start(3) + 1: m for m in found}
                if all(e[1] in bycol for e in group):
                    found = [bycol[e[1]] for e in group]
                else:
                    raise Skip('cannot place %s on line %d' % (name, ln))
            for m, e in zip(found, group):
                if e[4].startswith('amp:'):
                    var = e[4][4:]
                    if not m.group(1) or m.group(1).strip() != var:
                        raise Skip('cannot take the address on line %d' % ln)
                    ins.append((m.start(1), 1, '&'))
                    reps.append((m.start(3), m.end(3), e[3]))
                    continue
                reps.append((m.start(3), m.end(3), e[3]))
                cast = e[5]
                if cast:
                    mode, vt = cast
                    cs = chain_start(text, m.start(2))
                    if mode == 'value':
                        ins.append((cs, 1, '((%s)' % vt))
                        ins.append((m.end(3), 0, ')'))
                    elif mode == 'copy':
                        ins.append((cs, 1, '(*(%s *)&' % vt))
                        ins.append((m.end(3), 0, ')'))
                    else:  # addr: the & before the chain goes inside the cast
                        k = cs - 1
                        while k >= 0 and text[k] in ' \t':
                            k -= 1
                        if k < 0 or text[k] != '&':
                            raise Skip('address-of not found on line %d' % ln)
                        ins.append((k, 1, '((%s *)' % vt))
                        ins.append((m.end(3), 0, ')'))
        # rebuild: insertions (closing before opening at the same position), then replacements
        out, i = [], 0
        reps.sort()
        ins.sort(key=lambda x: (x[0], x[1]))
        ri = ii = 0
        while i <= len(text):
            while ii < len(ins) and ins[ii][0] == i:
                out.append(ins[ii][2])
                ii += 1
            if ri < len(reps) and reps[ri][0] == i:
                out.append(reps[ri][2])
                i = reps[ri][1]
                ri += 1
                continue
            if i < len(text):
                out.append(text[i])
            i += 1
        lines[ln - 1] = realign(lines[ln - 1], ''.join(out))
    return '\n'.join(lines)


def mask_comments(src):
    """Positions inside comments or string literals, as a boolean list."""
    inside = [False] * len(src)
    for m in re.finditer(r'/\*.*?\*/|//[^\n]*|"(?:[^"\\\n]|\\.)*"|\'(?:[^\'\\\n]|\\.)*\'', src, re.S):
        for i in range(m.start(), m.end()):
            inside[i] = True
    return inside


def definition_span(src, line):
    """(start, end) of the declaration that starts on `line` and ends at its `;` after `}`."""
    starts = [0]
    for m in re.finditer('\n', src):
        starts.append(m.end())
    s = starts[line - 1]
    i, depth, seen = s, 0, False
    while i < len(src):
        c = src[i]
        if c == '{':
            depth += 1
            seen = True
        elif c == '}':
            depth -= 1
        elif c == ';' and depth == 0 and seen:
            e = i + 1
            if e < len(src) and src[e] == '\n':
                e += 1
            return s, e
        i += 1
    raise Skip('end of the view definition not found')


def convert(path, canon, header, struct):
    cv = Conv(path, None, None)
    views = cv.local_views(canon)
    if not views:
        raise Skip('no view')
    rw = Rewriter(cv, canon, views)
    rw.run()
    src = cv.src
    new = apply_edits(src, rw.edits)
    # the view types
    for node, names, size, hits, misses in views:
        tag = node.name
        decl_line = None
        for ext in cv.ast.ext:
            if isinstance(ext, (c_ast.Typedef, c_ast.Decl)) and norm(ext.coord.file) == norm(path):
                if any(n is node for n in walk_types(ext.type)):
                    decl_line = node.coord.line if node.coord is not None else ext.coord.line
                    break
        if decl_line is None:
            raise Skip('view definition not found')
        if size <= canon.size:
            new = replace_view(new, decl_line, names, tag, struct)
        else:
            new = rebuild_extension(new, cv, node, decl_line, canon, struct)
    new = add_include(new, header)
    return new, len(rw.edits), len(views)


def replace_view(src, line, names, tag, struct):
    s, e = definition_span(src, line)
    # a comment right above the definition goes with it
    before = src[:s]
    m = re.search(r'/\*(?:(?!\*/).)*\*/[ \t]*\n$', before, re.S)
    if m:
        s = m.start()
    head, tail = src[:s].rstrip('\n'), src[e:].lstrip('\n')
    src = (head + '\n\n' if head else '') + tail
    kept = src
    inside = mask_comments(src)
    out, last = [], 0
    pats = []
    if tag:
        pats.append(r'\bstruct\s+%s\b' % re.escape(tag))
    for n in names:
        pats.append(r'\b%s\b' % re.escape(n))
    for m in re.finditer('|'.join(pats), src):
        if inside[m.start()]:
            continue
        out.append(src[last:m.start()])
        out.append(struct)
        last = m.end()
    out.append(src[last:])
    src = realign_lines(kept, ''.join(out))
    # forward declarations left behind
    src = re.sub(r'^[ \t]*typedef\s+%s\s+%s\s*;[^\n]*\n' % (struct, struct), '', src, flags=re.M)
    src = re.sub(r'^[ \t]*%s\s*;[^\n]*\n' % struct, '', src, flags=re.M)
    return src


def rebuild_extension(src, cv, node, line, canon, struct):
    T = cv.T
    fields, size, _ = T.fields(node)
    lines = src.split('\n')
    keep, first, covered = [], None, canon.size
    for (off, bp, bs, n, t), d in zip(fields, node.decls):
        s = T.size_align(t)[0]
        if off + s <= canon.size:
            continue
        if off < canon.size:
            if not re.match(r'_?(pad|unk|reserved)', n or '', re.I) or bs is not None:
                raise Skip('member %s straddles the end of the shared struct' % n)
            keep.append('    u8 pad%03x[0x%x];' % (canon.size, off + s - canon.size))
            covered = off + s
            continue
        if first is None and off > covered:
            keep.append('    u8 pad%03x[0x%x];' % (covered, off - covered))
        first = first or d.coord.line
    s, e = definition_span(src, line)
    body = src[s:e]
    ob, cb = body.index('{'), body.rindex('}')
    # the extension members' own lines, from the first extension member to the closing brace
    blines = body[ob + 1:cb].split('\n')
    start_line = src[:s].count('\n') + 1 + body[:ob + 1].count('\n')
    ext_lines = []
    if first is not None:
        ext_lines = blines[first - start_line:]
    inner = '\n    %s base;%s\n' % (struct, ' ' * max(1, 28 - len(struct) - 5) + '/* 0x000 */')
    inner += '\n'.join(keep + [l for l in ext_lines if l.strip() or True]).rstrip() + '\n'
    return src[:s] + body[:ob + 1] + inner + body[cb:] + src[e:]


def add_include(src, header):
    inc = '#include "%s"' % header
    if inc in src:
        return src
    incs = list(re.finditer(r'^#include[^\n]*\n', src, re.M))
    if incs:
        i = incs[-1].end()
        return src[:i] + inc + '\n' + src[i:]
    m = re.match(r'(\s*/\*.*?\*/)', src, re.S)
    if m:
        return src[:m.end()] + '\n\n' + inc + '\n\n' + src[m.end():].lstrip('\n')
    return inc + '\n\n' + src.lstrip('\n')


TRAIL = re.compile(r'^(.*?\S)([ \t]{2,})(/\*.*|//.*)$')


def realign(old, new):
    """Keep a trailing comment in the column it had before the code on its line changed length."""
    mo, mn = TRAIL.match(old), TRAIL.match(new)
    if not mo or not mn or mo.group(3) != mn.group(3):
        return new
    col = len(mo.group(1)) + len(mo.group(2))
    return mn.group(1) + ' ' * max(2, col - len(mn.group(1))) + mn.group(3)


def realign_lines(old_src, new_src):
    ol, nl = old_src.split('\n'), new_src.split('\n')
    if len(ol) != len(nl):
        return new_src
    return '\n'.join(realign(a, b) if a != b else b for a, b in zip(ol, nl))


def stage_and_verify(results):
    d = os.path.join(ROOT, 'build', 'structconv')
    shutil.rmtree(d, ignore_errors=True)
    where = {}
    for k, (p, t) in enumerate(results.items()):
        os.makedirs(os.path.join(d, str(k)))
        sp = os.path.join(d, str(k), os.path.basename(p)).replace(os.sep, '/')
        open(sp, 'wb').write(t.encode('utf-8'))
        where[sp] = p
    lst = os.path.join(ROOT, 'build', 'structconv_files.txt')
    open(lst, 'w', newline='\n').write(''.join(w + '\n' for w in where))
    r = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'verify_idx.py'), '--batch', '@' + lst],
                       capture_output=True, text=True, cwd=ROOT).stdout
    ok, why = set(), {}
    for line in r.splitlines():
        x = line.split('\t')
        if len(x) >= 3:
            p = where.get(x[0].replace(os.sep, '/'))
            if p is None:
                continue
            if x[1] == '0':
                ok.add(p)
            else:
                why[p] = x[2][:120]
    return ok, why


def load_canon(header, name):
    wrapper = os.path.join(ROOT, 'build', 'structconv_canon_%d.c' % os.getpid())
    open(wrapper, 'w').write('#include "%s"\n' % header)
    try:
        T = Types(parse(wrapper))
    finally:
        os.remove(wrapper)
    return Canon(T, name)


def _analyze_one(p):
    """(views, misses, declared types, error) of one source, all as plain data."""
    canon = _W['canon']
    try:
        cv = Conv(p, None, None)
        views = cv.local_views(canon, lenient=True)
        out = []
        for node, names, size, hits, misses in views:
            ms = [(off, bp, bs, cv.T.size_align(ft)[0], cv.T.spell(ft)) for off, bp, bs, n, ft in misses]
            ds = [(off, cv.T.spell(ft)) for off, bp, bs, n, ft in cv.T.fields(node)[0]
                  if n and off < canon.size and bs is None]
            out.append((hits, ms, ds, size))
        return p, out, None
    except Skip as e:
        return p, [], str(e).split(':')[0]
    except Exception as e:
        return p, [], 'error ' + type(e).__name__


def analyze(files, jobs, header, struct):
    """How the sources' views line up with the shared struct: which view members have no
    counterpart (by offset and shape) in views that are mostly the struct, and how the members
    that do are declared."""
    import multiprocessing
    miss = collections.Counter()
    decl = collections.defaultdict(collections.Counter)
    strict = near = nfiles = 0
    skipped = collections.Counter()
    with multiprocessing.Pool(jobs, initializer=_init_worker, initargs=(header, struct)) as pool:
        for p, views, err in pool.imap_unordered(_analyze_one, files, chunksize=8):
            if err:
                skipped[err] += 1
            if views:
                nfiles += 1
            for hits, ms, ds, size in views:
                if not ms:
                    strict += 1
                elif hits >= 2 * len(ms):
                    near += 1
                    for m in ms:
                        miss[m] += 1
                else:
                    continue
                for off, sp in ds:
                    decl[off][sp] += 1
    print('files with views %d; views matching %d, nearly %d; skipped %s' % (nfiles, strict, near, dict(skipped)))
    print('-- members with no counterpart in nearly matching views (offset, bit, size, type): count')
    for (off, bp, bs, s, sp), c in sorted(miss.items(), key=lambda kv: (kv[0][0], kv[0][1] or 0)):
        print('  0x%03x%s %3d %-44s %d' % (off, '' if bp is None else '.%d:%d' % (bp, bs), s, sp[:44], c))
    print('-- declared types per offset')
    for off in sorted(decl):
        print('  0x%03x %s' % (off, '; '.join('%s:%d' % kv for kv in decl[off].most_common(5))[:200]))


_W = {}


def _init_worker(header, struct):
    _W['canon'] = load_canon(header, struct)
    _W['header'], _W['struct'] = header, struct


def _convert_one(p):
    try:
        raw = open(p, 'rb').read().decode('utf-8')
        nl = '\r\n' if '\r\n' in raw else '\n'
        new, nedits, nviews = convert(p, _W['canon'], _W['header'], _W['struct'])
        return p, new.replace('\r\n', '\n').replace('\n', nl), '(%d views, %d accesses)' % (nviews, nedits)
    except Skip as e:
        return p, None, str(e)
    except Exception as e:  # a bug in the tool: report, keep going
        return p, None, 'error %s: %s' % (type(e).__name__, str(e)[:80])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--jobs', type=int, default=max(1, (os.cpu_count() or 2) - 1))
    ap.add_argument('--header')
    ap.add_argument('--struct')
    ap.add_argument('--analyze', action='store_true')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('files', nargs='*')
    a = ap.parse_args()
    if a.apply:
        plan = json.load(open(PLAN))
        for p, t in plan.items():
            open(p, 'wb').write(t.encode('utf-8'))
        print('applied', len(plan))
        return
    files = []
    for f in a.files:
        if f.startswith('@'):
            files += [x.strip() for x in open(f[1:]) if x.strip()]
        else:
            files += glob.glob(f) or [f]
    canon = load_canon(a.header, a.struct)
    if a.analyze:
        analyze(files, a.jobs, a.header, a.struct)
        return
    results, report = {}, []
    import multiprocessing
    with multiprocessing.Pool(a.jobs, initializer=_init_worker, initargs=(a.header, a.struct)) as pool:
        for p, new, msg in pool.imap_unordered(_convert_one, files, chunksize=8):
            if new is not None:
                results[p] = new
                report.append('STAGED %s %s' % (p, msg))
            elif msg != 'no view':
                report.append('SKIP %s | %s' % (p, msg))
    ok, why = stage_and_verify(results) if results else (set(), {})
    plan = {p: results[p] for p in ok}
    json.dump(plan, open(PLAN, 'w'), indent=0)
    for p in results:
        if p not in ok:
            report.append('FAIL %s | %s' % (p, why.get(p, '?')))
    open(REPORT, 'w', newline='\n').write('\n'.join(report) + '\n')
    skips = collections.Counter(re.sub(r'(line|at line) \d+|\(0x.*?\)|\b\w+_\w+\b', '', l.split('|', 1)[1]).strip()[:50]
                                for l in report if l.startswith('SKIP'))
    print('files %d, staged %d, match %d, fail %d, skipped %d' % (
        len(files), len(results), len(ok), len(results) - len(ok), sum(skips.values())))
    for k, v in skips.most_common(12):
        print('   skip %4d  %s' % (v, k))


if __name__ == '__main__':
    main()
