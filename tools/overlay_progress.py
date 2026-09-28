#!/usr/bin/env python3
"""Real per-overlay completion, counted the way the delinker counts it.

Two traps this avoids, both of which produced wrong targets before:

  1. Counting only `asm_stubs/` + `nonmatching/` as pending IGNORES functions that have
     no source file at all (the delinker's "gap"), which are usually the majority.
  2. A function's source does NOT have to live in its overlay's directory. Shared
     directories satisfy an overlay's delink too, and they are NOT all under src/:
     `src/engine` AND `libs/**/calls` both appear in overlay delinks.txt files.

The source of truth is the same one `gen_delinks.py` uses (tools/srctree.py): an overlay
function counts as done when SOME `.c` named after it exists in a function source directory.

    python tools/overlay_progress.py            # ranking of incomplete overlays
    python tools/overlay_progress.py ov000      # detail for one overlay
"""
import os
import re
import sys
import json

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CFG = os.path.join(ROOT, "config", "arm9", "overlays")


def all_sources():
    """Every function name that has C source (src/engine, an overlay directory, libs/**/{auto,calls})."""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import srctree
    return {name for name, path in srctree.function_sources(ROOT, (".c",)).items()
            if not srctree.is_asm_stub(path)}


def overlay_functions(ov):
    sym = os.path.join(CFG, ov, "symbols.txt")
    if not os.path.isfile(sym):
        return []
    out = []
    with open(sym, encoding="utf-8", errors="ignore") as fh:
        for line in fh:
            m = re.match(r"(\S+)\s+kind:function\(", line)
            if m:
                out.append(m.group(1))
    return out


def main():
    have = all_sources()
    idx_path = os.path.join(ROOT, "build", "func_index.json")
    idx = json.load(open(idx_path)) if os.path.isfile(idx_path) else {}

    if len(sys.argv) > 1:
        ov = sys.argv[1]
        funcs = overlay_functions(ov)
        missing = [f for f in funcs if f not in have]
        print("%s: %d/%d done, %d pending" % (ov, len(funcs) - len(missing), len(funcs), len(missing)))
        for f in missing:
            e = idx.get(f)
            print("   %-40s %s bytes" % (f, len(e["hex"]) // 2 if e else "?"))
        return

    rows = []
    for ov in sorted(os.listdir(CFG)):
        funcs = overlay_functions(ov)
        if not funcs:
            continue
        missing = [f for f in funcs if f not in have]
        if not missing:
            continue
        nbytes = sum(len(idx[f]["hex"]) // 2 for f in missing if f in idx)
        pct = 100.0 * (len(funcs) - len(missing)) / len(funcs)
        rows.append((len(missing), nbytes, -pct, ov, len(funcs)))

    rows.sort()
    print("%-8s %6s %9s %11s %s" % ("overlay", "pend", "bytes", "done/tot", "pct"))
    for pend, nb, negpct, ov, tot in rows[:25]:
        print("%-8s %6d %9d %6d/%-5d %.1f%%" % (ov, pend, nb, tot - pend, tot, -negpct))
    print("incomplete overlays: %d" % len(rows))


if __name__ == "__main__":
    main()
