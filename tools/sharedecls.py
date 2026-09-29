#!/usr/bin/env python3
"""Declare a module's functions once, in a header, instead of in every source that calls them.

The sources declare the functions they call with a local `extern` each, and those copies drift
from the definitions (other parameter types, a missing argument). This takes the prototypes of a
module's definitions whose types a header can provide (basic and SDK types, the shared game
structs in include/game/), writes them to a header, and moves every source that declares one of
them onto the header: its local declarations of those functions go, the `#include` comes in.
A source is kept only if it still compiles to the same bytes.

    python tools/sharedecls.py --module src/overlays/system/ov107_enemy_common \
        --header game/enemy_common.h --title "The enemy framework (ov107)" --uses game/actor.h
    python tools/sharedecls.py --apply

--uses names the headers the prototypes need (their types). Stage + verify writes
build/sharedecls_plan.json; --apply writes it (and the header).
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

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
import srctree  # noqa: E402

PLAN = os.path.join(ROOT, 'build', 'sharedecls_plan.json')
BASIC = set('u8 u16 u32 u64 s8 s16 s32 s64 vu8 vu16 vu32 fx16 fx32 fx64 BOOL VecFx32 VecFx16 '
            'int char short long unsigned signed void float double const volatile struct'.split())


def header_types(paths):
    """Type names the given headers declare (typedefs and struct tags)."""
    names = set()
    for h in paths:
        t = open(os.path.join(ROOT, 'include', h), encoding='utf-8').read()
        names |= set(re.findall(r'\btypedef\b[^;]*?\b(\w+)\s*;', t, re.S))
        names |= set(re.findall(r'\bstruct\s+(\w+)', t))
        names |= set(re.findall(r'\}\s*(\w+)\s*;', t))
    return names


def prototypes(module, known):
    """{function: prototype text} for the module's definitions whose types are all known."""
    src = srctree.function_sources()
    out = {}
    for f, p in src.items():
        p = p.strip().replace(os.sep, '/')
        if not p.startswith(module + '/'):
            continue
        t = open(os.path.join(ROOT, p), encoding='utf-8', errors='replace').read()
        m = re.search(r'^([^\n;#{}/*]*?\b%s\s*\(([^)]*)\))\s*\{' % re.escape(f), t, re.M)
        if not m or re.match(r'\s*static\b', m.group(1)):
            continue
        head = ' '.join(m.group(1).split())
        params = [x.strip() for x in m.group(2).split(',') if x.strip()]
        pnames = set()
        for x in params:
            w = re.findall(r'[A-Za-z_]\w*', x)
            if len(w) > 1 or (w and w[0] not in BASIC and w[0] not in known):
                pnames.add(w[-1])
        words = set(re.findall(r'[A-Za-z_]\w*', head)) - {f} - pnames
        if all(w in BASIC or w in known for w in words):
            out[f] = head + ';'
    return out


def write_header(path, title, uses, protos):
    guard = re.sub(r'\W', '_', path).upper()
    lines = ['#ifndef %s' % guard, '#define %s' % guard, '',
             '/* %s: the functions other modules call, declared as they are defined. */' % title, '']
    for u in ['nitro/types.h', 'nitro/fx_types.h'] + uses:
        lines.append('#include "%s"' % u)
    lines.append('')
    for f in sorted(protos):
        lines.append(protos[f])
    lines += ['', '#endif /* %s */' % guard, '']
    return '\n'.join(lines)


def rewrite(path, protos, header):
    raw = open(path, 'rb').read().decode('utf-8')
    nl = '\r\n' if '\r\n' in raw else '\n'
    t = raw.replace('\r\n', '\n')
    names = '|'.join(re.escape(n) for n in sorted(protos, key=len, reverse=True))
    # a local declaration: `extern ... F(...);` possibly over several lines, with a trailing comment
    pat = re.compile(r'^[ \t]*(?:extern\s+)?[^;{}()\n]*?\b(%s)\s*\([^;{}]*?\)\s*;[ \t]*(?:/\*[^\n]*?\*/)?[ \t]*\n' % names, re.M)
    removed = set()

    def drop(m):
        head = m.group(0)
        # only declarations at file scope (no leading indentation inside a function)
        if head.startswith((' ', '\t')) and not head.lstrip().startswith('extern'):
            return head
        removed.add(m.group(1))
        return ''
    t2 = pat.sub(drop, t)
    if not removed:
        return None, removed
    # the definition file itself keeps its definition; the header is included for the check
    inc = '#include "%s"' % header
    if inc not in t2:
        incs = list(re.finditer(r'^#include[^\n]*\n', t2, re.M))
        if incs:
            i = incs[-1].end()
            t2 = t2[:i] + inc + '\n' + t2[i:]
        else:
            m = re.match(r'(\s*/\*.*?\*/)', t2, re.S)
            if m:
                t2 = t2[:m.end()] + '\n\n' + inc + '\n' + t2[m.end():]
            else:
                t2 = inc + '\n\n' + t2
    t2 = re.sub(r'\n{3,}', '\n\n', t2)
    return t2.replace('\n', nl), removed


def split_args(s):
    out, d, cur = [], 0, ''
    for ch in s:
        d += {'(': 1, '[': 1, ')': -1, ']': -1}.get(ch, 0)
        if ch == ',' and d == 0:
            out.append(cur)
            cur = ''
        else:
            cur += ch
    return out + [cur]


class NotInformative(Exception):
    """A call would need a cast to a basic type (void *, int, char *...): it would say nothing, so
    the source keeps its own declarations until its code holds that value with a real type."""


BASIC_CAST = re.compile(r'^(const\s+)?(void|char|signed char|unsigned char|short|unsigned short|int|'
                        r'unsigned int|long|unsigned long|u8|u16|u32|s8|s16|s32|unsigned)(\s*\*+)?$')


def uninformative(spelled):
    return BASIC_CAST.match(' '.join(spelled.split())) is not None


def store_mismatch(T, a, b):
    """The cast a value of type a needs to be stored as type b (None when it needs none)."""
    if a is None or b is None:
        return None
    ak, bk = T.kind(a), T.kind(b)
    if ak not in ('ptr', 'scalar') or bk not in ('ptr', 'scalar') or ak == bk == 'scalar':
        return None
    if ak == bk == 'ptr':
        if T.spell(T.strip(a)) == T.spell(T.strip(b)):
            return None
        pa = T.spell(T.strip(a).type).replace('const ', '')
        pb = T.spell(T.strip(b).type).replace('const ', '')
        if pa == pb or pb == 'void':
            return None
    return T.spell(b)


def cast_arguments(path, text, protos):
    """Where a call passes a pointer (or an int) of another type than the parameter's, cast the
    argument to the parameter type. Returns the new text or None."""
    import structconv as sc
    tmp = os.path.join(ROOT, 'build', 'sharedecls_cast_%d.c' % os.getpid())
    open(tmp, 'wb').write(text.encode('utf-8'))
    try:
        cv = sc.Conv(tmp, None, None)
    except sc.Skip:
        return None
    finally:
        os.remove(tmp)
    T = cv.T
    edits = []  # (line, name, occurrence on the line, arg index, cast)

    rets = []  # (line, name, cast): the returned value stored with another type

    class Calls(sc.Rewriter):
        def walk(self, n, parent):
            if isinstance(parent, sc.c_ast.FuncDef) and n is parent.body:
                self.cur_ret = T.strip(parent.decl.type).type
            if isinstance(n, sc.c_ast.FuncCall) and isinstance(n.name, sc.c_ast.ID) and n.name.name in protos:
                self.on_call(n)
                self.on_return(n, parent)
            super().walk(n, parent)

        def on_return(self, n, parent):
            fd = T.funcs.get(n.name.name)
            if fd is None:
                return
            tgt = None
            if isinstance(parent, sc.c_ast.Assignment) and parent.rvalue is n and parent.op == '=':
                tgt = self.typeof(parent.lvalue)
            elif isinstance(parent, sc.c_ast.Decl) and parent.init is n:
                tgt = parent.type
            elif isinstance(parent, sc.c_ast.Return) and getattr(self, 'cur_ret', None) is not None:
                tgt = self.cur_ret
            elif isinstance(parent, sc.c_ast.ExprList):
                outer = self.parents.get(id(parent))
                if isinstance(outer, sc.c_ast.FuncCall) and isinstance(outer.name, sc.c_ast.ID):
                    od = T.funcs.get(outer.name.name)
                    od = T.strip(od) if od is not None else None
                    if od is not None and getattr(od, 'args', None):
                        ps = [x for x in od.args.params if isinstance(x, sc.c_ast.Decl)]
                        k = [i for i, e in enumerate(parent.exprs) if e is n]
                        if k and k[0] < len(ps):
                            tgt = ps[k[0]].type
            m = store_mismatch(T, T.strip(fd).type, tgt)
            if m is None:
                return
            if '{' in m:
                return
            if uninformative(m):
                raise NotInformative(n.name.name)
            rets.append((n.coord.line, n.name.name, m))

        def on_call(self, n):
            fd = T.funcs.get(n.name.name)
            if fd is None or not fd.args or n.args is None:
                return
            params = [p for p in fd.args.params if isinstance(p, sc.c_ast.Decl)]
            for i, (arg, prm) in enumerate(zip(n.args.exprs, params)):
                at, pt = self.typeof(arg), prm.type
                if at is None:
                    continue
                ak, pk = T.kind(at), T.kind(pt)
                if ak == 'array':
                    ak = 'ptr'
                    at = sc.c_ast.PtrDecl([], T.strip(at).type)
                if pk != 'ptr' and ak != 'ptr':
                    continue
                if ak == pk == 'ptr':
                    a_s, p_s = T.spell(T.strip(at)), T.spell(T.strip(pt))
                    if a_s == p_s or p_s == 'void *' or p_s.startswith('const void'):
                        continue
                    if a_s in ('void *', 'const void *') and uninformative(p_s):
                        continue  # C converts it; a cast to a basic type would say nothing
                    base_p = T.spell(T.strip(pt).type).replace('const ', '')
                    base_a = T.spell(T.strip(at).type).replace('const ', '')
                    if base_p == base_a:
                        continue
                elif isinstance(arg, sc.c_ast.Constant) and arg.value in ('0', '0x0'):
                    continue  # a null pointer
                spelled = T.spell(pt)
                if '{' in spelled:
                    return
                if uninformative(spelled):
                    raise NotInformative(n.name.name)
                edits.append((n.coord.line, n.name.name, i, spelled))

    rw = Calls(cv, None, [])
    try:
        rw.run()
    except sc.Skip:
        return None
    if not edits and not rets:
        return None
    lines = text.split('\n')
    for ln, name, m in rets:
        occ = list(re.finditer(r'\b%s\s*\(' % re.escape(name), lines[ln - 1]))
        if len(occ) != 1:
            return None
        s = occ[0].start()
        lines[ln - 1] = lines[ln - 1][:s] + '(%s)' % m + lines[ln - 1][s:]
    by = collections.defaultdict(list)
    for ln, name, i, spelled in edits:
        by[(ln, name)].append((i, spelled))
    for (ln, name), args in by.items():
        line = lines[ln - 1]
        m = list(re.finditer(r'\b%s\s*\(' % re.escape(name), line))
        if len(m) != 1:
            return None  # several calls of it on the line (or it spans lines): not placed
        j, d = m[0].end(), 1
        while j < len(line) and d:
            d += {'(': 1, ')': -1}.get(line[j], 0)
            j += 1
        if d:
            return None
        parts = split_args(line[m[0].end():j - 1])
        for i, spelled in args:
            if i >= len(parts):
                return None
            a = parts[i]
            lead = a[:len(a) - len(a.lstrip())]
            body = a.strip()
            simple = re.match(r'^[\w.\->\[\]&*]+$', body) and not body.startswith('*')
            parts[i] = lead + '(%s)%s' % (spelled, body if simple else '(' + body + ')')
        lines[ln - 1] = line[:m[0].end()] + ','.join(parts) + line[j - 1:]
    return '\n'.join(lines)


def verify(results):
    d = os.path.join(ROOT, 'build', 'sharedecls')
    shutil.rmtree(d, ignore_errors=True)
    where = {}
    for k, (p, t) in enumerate(results.items()):
        os.makedirs(os.path.join(d, str(k)))
        sp = os.path.join(d, str(k), os.path.basename(p)).replace(os.sep, '/')
        open(sp, 'wb').write(t.encode('utf-8'))
        where[sp] = p
    lst = os.path.join(ROOT, 'build', 'sharedecls_files.txt')
    open(lst, 'w', newline='\n').write(''.join(w + '\n' for w in where))
    r = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'verify_idx.py'), '--batch', '@' + lst],
                       capture_output=True, text=True, cwd=ROOT).stdout
    ok, why = set(), {}
    for line in r.splitlines():
        x = line.split('\t')
        if len(x) >= 3 and x[0].replace(os.sep, '/') in where:
            p = where[x[0].replace(os.sep, '/')]
            (ok.add(p) if x[1] == '0' else why.__setitem__(p, x[2][:100]))
    return ok, why


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--module')
    ap.add_argument('--header')
    ap.add_argument('--title', default='')
    ap.add_argument('--uses', default='')
    ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    if a.apply:
        plan = json.load(open(PLAN))
        for p, t in plan['files'].items():
            open(os.path.join(ROOT, p), 'wb').write(t.encode('utf-8'))
        open(os.path.join(ROOT, 'include', plan['header']), 'w', encoding='utf-8', newline='\n').write(plan['text'])
        print('applied', len(plan['files']), 'sources and', plan['header'])
        return
    uses = [u for u in a.uses.split(',') if u]
    protos = prototypes(a.module, header_types(uses))
    text = write_header(a.header, a.title, uses, protos)
    hpath = os.path.join(ROOT, 'include', a.header)
    old = open(hpath, encoding='utf-8').read() if os.path.exists(hpath) else None
    open(hpath, 'w', encoding='utf-8', newline='\n').write(text)   # staged sources compile against it
    try:
        results, removed = {}, {}
        for p in sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.c'), recursive=True)
                        + glob.glob(os.path.join(ROOT, 'libs', '**', '*.c'), recursive=True)):
            rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
            t = open(p, encoding='utf-8', errors='replace').read()
            if not any(f in t for f in protos):
                continue
            new, rm = rewrite(p, protos, a.header)
            if new is not None:
                results[rel] = new
                removed[rel] = rm
        # arguments of another type than the parameter get a cast (mwcc only warns about an int
        # or another pointer where a pointer is declared; the cast says what the caller passes)
        casted = kept = 0
        for p in list(results):
            try:
                t = cast_arguments(p, results[p], protos)
            except NotInformative:
                del results[p]      # keeps its own declarations for now
                kept += 1
                continue
            if t is not None and t != results[p]:
                results[p] = t
                casted += 1
        print('argument casts in %d sources; %d keep their declarations (a basic-type cast)' % (casted, kept))
        ok, why = verify(results)
    finally:
        if old is None:
            os.remove(hpath)
        else:
            open(hpath, 'w', encoding='utf-8', newline='\n').write(old)
    json.dump({'header': a.header, 'text': text, 'files': {p: results[p] for p in ok}}, open(PLAN, 'w'))
    reasons = collections.Counter(re.sub(r'@0x\w+|\d+ != \d+', '', w)[:50] for w in why.values())
    print('prototypes %d; sources %d, match %d, fail %d; declarations dropped %d' % (
        len(protos), len(results), len(ok), len(results) - len(ok), sum(len(removed[p]) for p in ok)))
    for k, v in reasons.most_common(6):
        print('   fail %5d  %s' % (v, k))
    open(os.path.join(ROOT, 'build', 'sharedecls_fail.txt'), 'w', newline='\n').write(
        ''.join('%s\t%s\n' % (p, w) for p, w in sorted(why.items())))


if __name__ == '__main__':
    main()
