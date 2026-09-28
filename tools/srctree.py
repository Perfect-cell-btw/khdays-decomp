"""Where the sources live (docs/layout.md). Every tool that looks for a source asks here.

    src/engine/                               the main module's game code (ITCM included)
    src/engine/data/                          its reconstructed DATA
    src/overlays/<group>/ovNNN[_name]/        one directory per overlay, functions directly in it
    src/overlays/<group>/ovNNN[_name]/data/   the overlay's reconstructed DATA
    libs/<vendor>/<module>/{auto,calls}/                  library C
    libs/<vendor>/<module>/asm_stubs/{auto,calls}/        original library assembly

A function's source is named after its symbol, so a function is found by name wherever its
directory is. The number in an overlay directory is the FS overlay id the game loads by; the
suffix only says what the overlay is (bare `ovNNN` while that is not established).
"""
import os
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# directories under src/ that hold something other than function sources
NOT_FUNCTIONS = {"data", "dsprot", "nonmatching", "asm_stubs", "include"}
LIB_SUBDIRS = ("auto", "calls", "asm_stubs/auto", "asm_stubs/calls")
OVERLAY_DIR = re.compile(r"^(ov\d{3})(?:_[A-Za-z0-9_]+)?$")
OVERLAY_IN_PATH = re.compile(r"(?:^|/)overlays/[^/]+/(ov\d{3})(?:_[A-Za-z0-9_]+)?/")
SOURCE_SUFFIXES = (".c", ".cpp", ".s")


def overlay_dirs(root=ROOT):
    """{'ov000': Path('src/overlays/scenes/ov000_title'), ...} for every overlay with a directory."""
    out = {}
    base = Path(root) / "src" / "overlays"
    if base.is_dir():
        for group in sorted(base.iterdir()):
            if not group.is_dir():
                continue
            for d in sorted(group.iterdir()):
                m = OVERLAY_DIR.match(d.name)
                if d.is_dir() and m:
                    if m.group(1) in out:
                        raise ValueError("two directories for %s: %s, %s" % (m.group(1), out[m.group(1)], d))
                    out[m.group(1)] = d
    return out


def module_dir(module, root=ROOT):
    """The source directory of a module: 'main'/'itcm'/'dtcm' -> src/engine, 'ovNNN' -> its overlay."""
    if module in ("main", "itcm", "dtcm", "arm9"):
        return Path(root) / "src" / "engine"
    return overlay_dirs(root).get(module)


def overlay_of(path):
    """'ov114' for any path inside src/overlays/<group>/ov114_*/ (posix or native), else None."""
    m = OVERLAY_IN_PATH.search(str(path).replace("\\", "/"))
    return m.group(1) if m else None


def function_source_dirs(root=ROOT):
    """Every directory that can hold a function source (not DATA, not DS Protect, not parked C)."""
    root = Path(root)
    out = []
    src = root / "src"
    if src.is_dir():
        for dirpath, dirnames, _files in os.walk(src):
            dirnames[:] = sorted(d for d in dirnames if d not in NOT_FUNCTIONS)
            out.append(Path(dirpath))
    libs = root / "libs"
    if libs.is_dir():
        for vendor in sorted(libs.iterdir()):
            if not vendor.is_dir():
                continue
            for mod in sorted(vendor.iterdir()):
                if not mod.is_dir():
                    continue
                out.extend(mod / sub for sub in LIB_SUBDIRS if (mod / sub).is_dir())
    return out


def function_sources(root=ROOT, suffixes=SOURCE_SUFFIXES):
    """{function name: posix path relative to root} for every function source."""
    root = Path(root)
    out = {}
    for d in function_source_dirs(root):
        for p in sorted(d.iterdir()):
            if p.is_file() and p.suffix in suffixes:
                out[p.stem] = p.relative_to(root).as_posix()
    return out


def all_sources(root=ROOT, suffixes=SOURCE_SUFFIXES):
    """{stem: posix path} for every source file under src/ and libs/, DATA and DS Protect included."""
    root = Path(root)
    out = {}
    for top in ("src", "libs"):
        base = root / top
        if not base.is_dir():
            continue
        for dirpath, dirnames, files in os.walk(base):
            dirnames[:] = sorted(d for d in dirnames if d != "nonmatching")
            for f in sorted(files):
                if f.endswith(suffixes):
                    p = Path(dirpath) / f
                    out.setdefault(p.stem, p.relative_to(root).as_posix())
    return out


def is_asm_stub(path):
    return "asm_stubs" in Path(str(path).replace("\\", "/")).parts
