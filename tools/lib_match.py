#!/usr/bin/env python3
"""Label statically linked library functions by masked-byte matching against OMF libraries.

For every module in the given OMF libraries (e.g. Open Watcom `clib3r.lib`, `math3r.lib`), every
public in a CODE segment is cut out (sized to the next public / segment end, trailing zero or
nop fill stripped), its relocated bytes are masked, and the result is searched at every
function start in configs/DOS/functions.csv. A hit requires the first PREFIX (48) bytes to agree on
every unmasked byte, with at least 16 unmasked bytes. The same idea as OpenWINGS' lib_match.py for DJGPP.

Output: configs/DOS/lib_symbols.csv (va, name, library, module) and a summary. Names are
evidence for configs/DOS/symbols.txt (Open Watcom descends from Watcom 11, so an exact hit means
the Watcom 10 routine was unchanged; misses prove nothing).

usage: lib_match.py <lib.lib> [<lib.lib> ...]
"""
import csv
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from le import LE  # noqa: E402
from omf import OMF  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PREFIX = 48        # compare at most this many leading bytes (whole bodies drift between versions)
MIN_UNMASKED = 16  # and require this many unmasked bytes for a hit


def lib_modules(path):
    """Yield (module_name, obj_bytes) from an OMF library (0xF0 header, page-aligned modules)."""
    d = open(path, "rb").read()
    if d[0] != 0xF0:
        raise ValueError("not an OMF library: %s" % path)
    page = struct.unpack_from("<H", d, 1)[0] + 3
    p = page
    while p < len(d):
        if d[p] == 0xF1:  # library end
            break
        start = p
        name = "?"
        while p < len(d):
            t = d[p]
            ln = struct.unpack_from("<H", d, p + 1)[0]
            if t == 0x80 and name == "?":
                n = d[p + 3]
                name = d[p + 4:p + 4 + n].decode("latin1")
            p += 3 + ln
            if t in (0x8A, 0x8B):  # MODEND
                break
        yield name, d[start:p]
        p = (p + page - 1) // page * page


class _Mem(OMF):
    def __init__(self, data):  # noqa: super-init not called on purpose (parse from bytes)
        self.path = "<mem>"
        self.lnames = [None]
        self.segs = [None]
        self.groups = [None]
        self.exts = [None]
        self.publics = {}
        self.data = {}
        self.fixups = []
        self._parse(data)


def main():
    le = LE(os.path.join(ROOT, "dumps", "disc", "KKND", "KKND.EXE"))
    code = le.objs[0]
    raw = bytes(le.load(relocate=False)[code.index])
    fix = set()
    for f in le.fixups():
        for k in range(f.size):
            fix.add(f.src_va + k)
    funcs = []
    with open(os.path.join(ROOT, "configs", "DOS", "functions.csv"), newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["va"], 16), int(r["size"]), int(r["span"])))
    hits = {}
    for lib in sys.argv[1:]:
        for mod, blob in lib_modules(lib):
            try:
                o = _Mem(blob)
            except Exception:
                continue
            for pub, si, off, size in o.functions():
                body = bytes(o.data[si][off:off + size])
                trimmed = body.rstrip(b"\x00\x90")[:PREFIX]
                if len(trimmed) < 8:
                    continue
                mask = set()
                for fx in o.fixups:
                    if fx.seg == si and off <= fx.offset < off + len(trimmed):
                        mask.update(range(fx.offset - off, fx.offset - off + fx.size))
                if len(trimmed) - len(mask) < MIN_UNMASKED:
                    continue
                for va, fsize, span in funcs:
                    if len(trimmed) > span:
                        continue
                    b = raw[va - code.base: va - code.base + len(trimmed)]
                    if all(k in mask or va + k in fix or b[k] == trimmed[k] for k in range(len(trimmed))):
                        hits.setdefault(va, []).append((pub, os.path.basename(lib), mod, len(trimmed)))
    out = os.path.join(ROOT, "configs", "DOS", "lib_symbols.csv")
    with open(out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["va", "name", "library", "module", "bytes"])
        for va in sorted(hits):
            best = max(hits[va], key=lambda h: h[3])
            w.writerow(["0x%08X" % va, best[0], best[1], best[2], best[3]])
    print("%d functions labelled -> %s" % (len(hits), os.path.relpath(out, ROOT)))


if __name__ == "__main__":
    main()
