#!/usr/bin/env python3
"""Lay out every local definition of a struct and line them up by offset.

The sources declare the game's structs locally, each file only the fields it touches (a partial
view, padded to the right offsets). Before a struct can move into include/, the views have to
agree. This reads the struct definitions of each file (not the functions), lays them out the way
mwcc does for ARM (char 1, short 2, int/long/pointer/float 4, long long/double 8 -- aligned to
their size; bitfields packed LSB-first into units of their declared type), and prints, per
offset, every name and type the files use there.

    python tools/structviews.py MissionContext src/overlays/scenes/ov008_camp_menu/*.c ...
    python tools/structviews.py MissionContext --json out.json FILES...
"""
import json
import re
import sys

from pycparser import c_ast, c_parser

BASE = """
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned long u32;
typedef unsigned long long u64; typedef signed char s8; typedef short s16; typedef long s32;
typedef long long s64; typedef volatile u8 vu8; typedef volatile u16 vu16; typedef volatile u32 vu32;
typedef int BOOL; typedef float f32; typedef short fx16; typedef long fx32; typedef long long fx64;
typedef struct VecFx32 { fx32 x; fx32 y; fx32 z; } VecFx32;
typedef struct VecFx16 { fx16 x; fx16 y; fx16 z; } VecFx16;
typedef int OSIntrMode; typedef u64 OSTick;
"""
SIZES = {'char': 1, 'signed char': 1, 'unsigned char': 1, 'short': 2, 'unsigned short': 2,
         'short int': 2, 'unsigned short int': 2, 'signed short': 2,
         'int': 4, 'unsigned int': 4, 'signed int': 4, 'unsigned': 4, 'signed': 4, 'long': 4,
         'unsigned long': 4, 'signed long': 4, 'long int': 4, 'unsigned long int': 4, 'float': 4,
         'long long': 8, 'unsigned long long': 8, 'signed long long': 8, 'double': 8, '_Bool': 1}


def strip(t):
    t = re.sub(r'/\*.*?\*/', ' ', t, flags=re.S)
    t = re.sub(r'//[^\n]*', ' ', t)
    t = re.sub(r'^\s*#[^\n]*(\\\n[^\n]*)*', ' ', t, flags=re.M)
    t = re.sub(r'__attribute__\s*\(\(.*?\)\)', ' ', t)
    return t


def declarations(t):
    """The top-level struct/union/enum/typedef declarations of a source, in order."""
    out, i, n = [], 0, len(t)
    depth = 0
    start = None
    while i < n:
        c = t[i]
        if depth == 0 and start is None:
            m = re.match(r'(typedef\b|struct\s+\w+\s*\{|union\s+\w+\s*\{|enum\b)', t[i:])
            if m and (i == 0 or not (t[i - 1].isalnum() or t[i - 1] == '_')):
                start = i
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
        elif c == ';' and depth == 0:
            if start is not None:
                d = t[start:i + 1]
                if '(' not in d.split('{')[0] or d.lstrip().startswith('typedef'):
                    out.append(d)
                start = None
        i += 1
    return out


class Layout:
    def __init__(self, ast):
        self.typedefs, self.tags = {}, {}
        for ext in ast.ext:
            self._collect(ext)

    def _collect(self, node):
        if isinstance(node, c_ast.Typedef):
            self.typedefs[node.name] = node.type
            self._tag(node.type)
        elif isinstance(node, c_ast.Decl):
            self._tag(node.type)

    def _tag(self, t):
        while isinstance(t, (c_ast.TypeDecl, c_ast.PtrDecl, c_ast.ArrayDecl)):
            if isinstance(t, c_ast.PtrDecl):
                return
            t = t.type
        if isinstance(t, (c_ast.Struct, c_ast.Union)) and t.name and t.decls is not None:
            self.tags[('u' if isinstance(t, c_ast.Union) else 's') + t.name] = t

    def resolve(self, t):
        """(kind, node) with typedefs followed: kind in scalar/ptr/array/struct/union/enum."""
        if isinstance(t, c_ast.TypeDecl):
            t = t.type
        if isinstance(t, c_ast.PtrDecl):
            return 'ptr', t
        if isinstance(t, c_ast.ArrayDecl):
            return 'array', t
        if isinstance(t, c_ast.IdentifierType):
            name = ' '.join(n for n in t.names if n not in ('volatile', 'const'))
            if name in self.typedefs:
                return self.resolve(self.typedefs[name])
            return 'scalar', name
        if isinstance(t, (c_ast.Struct, c_ast.Union)):
            if t.decls is None:
                t = self.tags.get(('u' if isinstance(t, c_ast.Union) else 's') + (t.name or ''), t)
            return ('union' if isinstance(t, c_ast.Union) else 'struct'), t
        if isinstance(t, c_ast.Enum):
            return 'enum', t
        raise ValueError('type %r' % t)

    def size_align(self, t):
        kind, node = self.resolve(t)
        if kind == 'scalar':
            s = SIZES[node]
            return s, s
        if kind in ('ptr', 'enum'):
            return 4, 4
        if kind == 'array':
            s, a = self.size_align(node.type)
            dim = node.dim
            n = eval_const(dim) if dim is not None else 0
            return s * n, a
        fields = self.fields(node, kind == 'union')
        return fields[1], fields[2]

    def fields(self, node, union=False):
        """([(offset, bitpos, bitsize, name, typenode)], size, align) of a struct/union."""
        out, off, align, unit = [], 0, 1, None   # unit = (start, size, used bits)
        for d in node.decls or []:
            s, a = self.size_align(d.type)
            align = max(align, a)
            if d.bitsize is not None:
                bits = eval_const(d.bitsize)
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
            if union:
                out.append((0, None, None, d.name, d.type))
                off = max(off, s)
                continue
            start = (off + a - 1) // a * a
            out.append((start, None, None, d.name, d.type))
            off = start + s
        size = (off + align - 1) // align * align
        return out, size, align

    def spell(self, t):
        kind, node = self.resolve(t)
        if kind == 'scalar':
            return node
        if kind == 'ptr':
            return 'ptr'
        if kind == 'enum':
            return 'enum'
        if kind == 'array':
            return '%s[%d]' % (self.spell(node.type), eval_const(node.dim) if node.dim is not None else 0)
        return kind + ' ' + (node.name or '?')

    def flatten(self, node, base=0, path='', union=False):
        """Leaves: (offset, bitpos, bitsize, size, spelled type, dotted path)."""
        out = []
        fields, _, _ = self.fields(node, union)
        for off, bp, bs, name, t in fields:
            kind, sub = self.resolve(t)
            p = (path + '.' if path else '') + (name or '?')
            if kind in ('struct', 'union') and bs is None:
                out += self.flatten(sub, base + off, p, kind == 'union')
            else:
                s, _ = self.size_align(t)
                out.append((base + off, bp, bs, s, self.spell(t), p))
        return out


def eval_const(e):
    if isinstance(e, c_ast.Constant):
        v = e.value.rstrip('uUlL')
        return int(v, 0)
    if isinstance(e, c_ast.BinaryOp):
        a, b = eval_const(e.left), eval_const(e.right)
        return {'+': a + b, '-': a - b, '*': a * b, '/': a // b, '<<': a << b, '>>': a >> b}[e.op]
    if isinstance(e, c_ast.UnaryOp) and e.op == '-':
        return -eval_const(e.expr)
    if isinstance(e, c_ast.UnaryOp) and e.op == 'sizeof':
        raise ValueError('sizeof')
    raise ValueError('const %r' % e)


def view(path, name):
    t = strip(open(path, encoding='utf-8', errors='replace').read())
    decls = declarations(t)
    src = BASE + '\n'.join(decls)
    ast = c_parser.CParser().parse(src, filename=path)
    lay = Layout(ast)
    node = None
    if name in lay.typedefs:
        kind, node = lay.resolve(lay.typedefs[name])
    elif 's' + name in lay.tags:
        node = lay.tags['s' + name]
    if node is None:
        return None
    _, size, _ = lay.fields(node)
    return size, lay.flatten(node)


def main():
    args = sys.argv[1:]
    name = args.pop(0)
    out_json = None
    if '--json' in args:
        k = args.index('--json')
        out_json = args[k + 1]
        del args[k:k + 2]
    table, sizes, errors = {}, {}, {}
    for p in args:
        try:
            v = view(p, name)
        except Exception as e:  # noqa: BLE001
            errors[p] = str(e)[:120]
            continue
        if v is None:
            continue
        sizes[p] = v[0]
        for off, bp, bs, s, ty, path in v[1]:
            if path.split('.')[-1].startswith(('pad', '_pad', 'unk', 'padding', 'reserved', 'unused', '_')) and bs is None:
                continue
            key = (off, bp if bp is not None else -1)
            table.setdefault(key, []).append((p.replace('\\', '/').split('/')[-1], path, ty, s, bs))
    for p, e in errors.items():
        print('ERROR', p, e)
    print('views', len(sizes), 'sizes', sorted(set(sizes.values())))
    for (off, bp) in sorted(table):
        rows = table[(off, bp)]
        kinds = sorted(set((r[2], r[3], r[4]) for r in rows))
        names = sorted(set(r[1] for r in rows))
        flag = '' if len(kinds) == 1 else '  <-- TYPES DIFFER'
        where = '0x%04x' % off + ('.%d' % bp if bp >= 0 else '')
        print('%-9s %-40s %s%s' % (where, ', '.join(names)[:40], kinds, flag))
    if out_json:
        json.dump({'sizes': sizes, 'errors': errors,
                   'table': [[k[0], k[1], v] for k, v in sorted(table.items())]}, open(out_json, 'w'), indent=0)


if __name__ == '__main__':
    main()
