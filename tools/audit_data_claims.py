#!/usr/bin/env python3
"""Fail when the regenerated delinks.txt files stop claiming DATA that HEAD's claimed.

Why this exists (2026-09-28): a DATA range leaves the build without a sound. dsd fills an
unclaimed range with the original ROM bytes, so the linked-module gate stays at 306 while the
table is no longer built from source. It happened twice in one day: a rename pass changed the
digest of twelve DATA sources (stale receipts, now gate step 3b), and renaming a function file
dropped the claim on its local .rodata, which lives only in the committed delinks.txt under the
old path. This compares every data range HEAD's delinks.txt files claim against the ones
configure just wrote; a range no longer covered by any source is reported.

Usage:  python tools/audit_data_claims.py [REV]      # default REV = HEAD
Removing a claim on purpose (its source moved to nonmatching/, say): KHDAYS_ALLOW_CLAIM_LOSS=1
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA_LINE = re.compile(r"^\s+\.(rodata|data|ctor|bss)\s+start:0x([0-9a-f]+)\s+end:0x([0-9a-f]+)")
FILE_LINE = re.compile(r"^(\S+\.(?:c|cpp|s)):\s*$")


def git(*args):
    return subprocess.run(["git", *args], capture_output=True, text=True, cwd=ROOT).stdout


def claims(text):
    """{(section, start, end): source} for the FILE blocks (the module header is skipped)."""
    parts = re.split(r"\n\s*\n", text, maxsplit=1)
    out = {}
    source = None
    for line in (parts[1] if len(parts) > 1 else "").splitlines():
        m = FILE_LINE.match(line)
        if m:
            source = m.group(1)
            continue
        m = DATA_LINE.match(line)
        if m:
            out[(m.group(1), int(m.group(2), 16), int(m.group(3), 16))] = source
    return out


def uncovered(old, new):
    spans = {}
    for sec, s, e in new:
        spans.setdefault(sec, []).append((s, e))
    lost = []
    for (sec, s, e), source in sorted(old.items()):
        pos = s
        for ns, ne in sorted(spans.get(sec, [])):
            if ns <= pos < ne:
                pos = ne
        if pos < e:
            lost.append((sec, s, e, source))
    return lost


def main():
    rev = sys.argv[1] if len(sys.argv) > 1 else "HEAD"
    paths = [p for p in git("ls-tree", "-r", "--name-only", rev, "config/arm9").split()
             if p.endswith("delinks.txt")]
    lost = []
    for path in paths:
        full = os.path.join(ROOT, path)
        now = open(full, encoding="utf-8").read() if os.path.isfile(full) else ""
        for sec, s, e, source in uncovered(claims(git("show", "%s:%s" % (rev, path))), claims(now)):
            lost.append("  %s .%s 0x%08x-0x%08x (was %s)" % (path, sec, s, e, source))
    print("data claims lost against %s: %d" % (rev, len(lost)))
    if lost:
        print("\n".join(lost[:50]))
    if lost and os.environ.get("KHDAYS_ALLOW_CLAIM_LOSS") != "1":
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
