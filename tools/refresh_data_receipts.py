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


def verify_command(sym, receipt):
    """The verifier call that re-proves one receipt, by receipt kind."""
    tools = os.path.join(ROOT, "tools")
    source = os.path.join(ROOT, receipt["source"])
    kind = receipt.get("kind")
    if kind == "section_range":  # a function's local .rodata, verified as one span
        return [os.path.join(tools, "verify_data.py"), source, "--section-range", receipt["module"],
                receipt["section"], "0x%08x" % receipt["start"], "--receipt"]
    if kind == "dsprot_encrypted_code":
        return [os.path.join(tools, "verify_dsprot.py"), source, "--receipt"]
    if sym.startswith("executable_"):
        return [os.path.join(tools, "verify_executable_data.py"), source, sym[len("executable_"):],
                "--receipt"]
    return [os.path.join(tools, "verify_data.py"), source, sym, "--receipt"]


def verify(sym, receipt):
    res = subprocess.run([sys.executable] + verify_command(sym, receipt),
                         capture_output=True, text=True, cwd=ROOT)
    ok = res.returncode == 0 and "MATCH" in res.stdout
    return sym, receipt["source"], ok, (res.stdout + res.stderr)[-400:]


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
            by_source.setdefault(r["source"], []).append((os.path.splitext(os.path.basename(path))[0], r))
    from concurrent.futures import ThreadPoolExecutor

    def run_group(item):
        _source, receipts = item
        return [verify(sym, r) for sym, r in receipts]

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
