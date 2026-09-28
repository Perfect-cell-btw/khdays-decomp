#!/usr/bin/env python3
"""Re-verify every DATA receipt whose source changed since it was written.

Why this exists (2026-09-28): gen_delinks.py only links a reconstructed DATA source while its
receipt's source_sha256 matches the file. A mechanical edit that does not change a single byte
of output -- renaming a function that a pointer table references -- changes the digest, so the
source silently drops out of delinks.txt and dsd fills the range with the original ROM bytes.
The linked-module gate stays green (the bytes are identical), but the data is no longer built
from source: a rename pass dropped twelve function-pointer tables that way. After any tree-wide
edit, run this, then configure; it re-checks each stale receipt with verify_data.py (bytes and
relocations against the ROM) and only rewrites the receipt when the source still verifies.

Usage:  python tools/refresh_data_receipts.py          # report stale receipts
        python tools/refresh_data_receipts.py --fix    # re-verify them and rewrite receipts
"""
import glob
import hashlib
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def stale_receipts():
    out = []
    for path in sorted(glob.glob(os.path.join(ROOT, "build", "data_receipts", "*.json"))):
        r = json.load(open(path, encoding="utf-8"))
        src = os.path.join(ROOT, r.get("source", ""))
        if not os.path.isfile(src):
            out.append((path, r, "source missing"))
            continue
        if hashlib.sha256(open(src, "rb").read()).hexdigest() != r.get("source_sha256"):
            out.append((path, r, "source changed"))
    return out


def verify(sym, source):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "verify_data.py"),
                          os.path.join(ROOT, source), sym, "--receipt"],
                         capture_output=True, text=True, cwd=ROOT)
    ok = res.returncode == 0 and "MATCH" in res.stdout
    return sym, source, ok, (res.stdout + res.stderr)[-400:]


def main():
    fix = "--fix" in sys.argv
    stale = stale_receipts()
    print("stale DATA receipts: %d" % len(stale))
    if not fix:
        for path, r, why in stale[:50]:
            print("  %-40s %s (%s)" % (os.path.splitext(os.path.basename(path))[0], r.get("source"), why))
        return 1 if stale else 0
    # verify_data compiles <source>.o, so symbols of ONE source run in sequence; sources in parallel
    by_source = {}
    for path, r, why in stale:
        if why == "source changed":
            by_source.setdefault(r["source"], []).append(os.path.splitext(os.path.basename(path))[0])
    from concurrent.futures import ThreadPoolExecutor

    def run_group(item):
        source, syms = item
        return [verify(sym, source) for sym in syms]

    bad = 0
    with ThreadPoolExecutor(max_workers=max(2, (os.cpu_count() or 4) - 1)) as pool:
        for results in pool.map(run_group, sorted(by_source.items())):
            for sym, source, ok, out in results:
                if not ok:
                    bad += 1
                    print("  FAIL %-35s %s" % (sym, source))
                    print(out)
    print("re-verified %d, failed %d" % (sum(len(v) for v in by_source.values()) - bad, bad))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
