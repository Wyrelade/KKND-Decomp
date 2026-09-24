#!/usr/bin/env python3
"""Linear Executable (LE) reader for the DOS/4GW-bound KKND.EXE.

KKND.EXE = MZ stub + DOS/4GW Professional (bound) + a Watcom LE image. This module parses the
LE header, object table, object page map and fixup tables, and loads every object into a flat
bytearray at its linear base address (LE `reloc base`, e.g. object 1 at 0x10000).

Fixups are returned as `Fixup(src_va, kind, target_va, target_obj, size)`; `src_va` is the address
of the patched field, `target_va` the linear address it resolves to (object base + offset).
Pages in the file hold the *unrelocated* bytes, which is exactly what we want for matching: the
32-bit offset fields contain the target offset relative to its object, not the final address.

usage (CLI): le.py <KKND.EXE>   -- prints a header / object / fixup summary
"""
import struct
import sys
from collections import namedtuple

Obj = namedtuple("Obj", "index vsize base flags page_index page_count")
Fixup = namedtuple("Fixup", "src_va kind target_va target_obj size")

# LE source types (low nibble of the source byte)
SRC_BYTE, SRC_SEL16, SRC_PTR1616, SRC_OFF16, SRC_PTR1632, SRC_OFF32, SRC_REL32 = 0, 2, 3, 5, 6, 7, 8
SRC_SIZE = {SRC_BYTE: 1, SRC_SEL16: 2, SRC_PTR1616: 4, SRC_OFF16: 2, SRC_PTR1632: 6,
            SRC_OFF32: 4, SRC_REL32: 4}


class LE:
    def __init__(self, path):
        self.path = path
        self.data = open(path, "rb").read()
        d = self.data
        # The bound DOS/4GW loader is itself an MZ with its own header; the LE header offset is
        # stored at 0x3C of the *first* MZ. Fall back to a signature scan if it does not point at LE.
        off = struct.unpack_from("<I", d, 0x3C)[0]
        if d[off:off + 2] != b"LE":
            off = self._scan_le()
        self.le_off = off
        h = lambda fmt, o: struct.unpack_from(fmt, d, off + o)[0]
        self.page_size = h("<I", 0x28)
        self.last_page_size = h("<I", 0x2C)
        self.num_pages = h("<I", 0x14)
        self.eip_obj, self.eip = h("<I", 0x18), h("<I", 0x1C)
        self.esp_obj, self.esp = h("<I", 0x20), h("<I", 0x24)
        self.fixup_size = h("<I", 0x30)
        self.loader_size = h("<I", 0x38)
        self.obj_tab = off + h("<I", 0x40)
        self.num_objs = h("<I", 0x44)
        self.page_map = off + h("<I", 0x48)
        self.fixup_page_tab = off + h("<I", 0x68)
        self.fixup_rec_tab = off + h("<I", 0x6C)
        # Data-page offset is relative to the MZ stub that owns this LE header (the bound DOS/4GW
        # loader sits in front of it). For KKND.EXE that stub is at 0x26654, not 0.
        self.stub_off = self._find_stub(off)
        self.data_pages = self.stub_off + h("<I", 0x80)
        self.objs = []
        for i in range(self.num_objs):
            vs, base, fl, pti, npe, _ = struct.unpack_from("<6I", d, self.obj_tab + i * 24)
            self.objs.append(Obj(i + 1, vs, base, fl, pti, npe))
        self.pages = []  # (file_offset, length, flags) indexed by logical page - 1
        for p in range(self.num_pages):
            e = d[self.page_map + p * 4: self.page_map + p * 4 + 4]
            num = (e[0] << 16) | (e[1] << 8) | e[2]
            flags = e[3]
            length = self.last_page_size if p == self.num_pages - 1 else self.page_size
            self.pages.append((self.data_pages + (num - 1) * self.page_size, length, flags))
        self.entry_va = self.objs[self.eip_obj - 1].base + self.eip

    def _find_stub(self, le_off):
        d = self.data
        i = le_off
        while i > 0:
            i = d.rfind(b"MZ", 0, i)
            if i < 0:
                break
            if i + struct.unpack_from("<I", d, i + 0x3C)[0] == le_off:
                return i
        return 0

    def _scan_le(self):
        d = self.data
        i = 0
        while True:
            i = d.find(b"LE\x00\x00", i)
            if i < 0:
                raise ValueError("no LE header found")
            # sanity: page size 4096
            if struct.unpack_from("<I", d, i + 0x28)[0] == 0x1000:
                return i
            i += 1

    def obj_of_va(self, va):
        for o in self.objs:
            if o.base <= va < o.base + o.vsize:
                return o
        return None

    def load(self, relocate=False):
        """Return {obj_index: bytearray(vsize)} with page data copied in (bss stays zero).

        With relocate=True every 32-bit offset fixup is applied (field := target linear address),
        which is what the loader does and what a disassembler wants. Without it the fields keep
        the raw file contents (object-relative offsets)."""
        out = {}
        for o in self.objs:
            buf = bytearray(o.vsize)
            for k in range(o.page_count):
                fo, ln, fl = self.pages[o.page_index - 1 + k]
                if fl != 0:
                    raise NotImplementedError("page flags %#x (iterated/zero pages)" % fl)
                chunk = self.data[fo:fo + ln]
                dst = k * self.page_size
                n = min(len(chunk), max(0, o.vsize - dst))
                buf[dst:dst + n] = chunk[:n]
            out[o.index] = buf
        if relocate:
            for f in self.fixups():
                if f.kind != SRC_OFF32:
                    continue
                so = self.obj_of_va(f.src_va)
                struct.pack_into("<I", out[so.index], f.src_va - so.base, f.target_va)
        return out

    def page_va(self, page_no):
        """Linear address of logical page `page_no` (1-based)."""
        for o in self.objs:
            if o.page_index <= page_no < o.page_index + o.page_count:
                return o.base + (page_no - o.page_index) * self.page_size
        raise ValueError(page_no)

    def fixups(self):
        d = self.data
        out = []
        for p in range(self.num_pages):
            start = struct.unpack_from("<I", d, self.fixup_page_tab + p * 4)[0]
            end = struct.unpack_from("<I", d, self.fixup_page_tab + (p + 1) * 4)[0]
            pos, stop = self.fixup_rec_tab + start, self.fixup_rec_tab + end
            pva = self.page_va(p + 1)
            while pos < stop:
                src, flg = d[pos], d[pos + 1]
                pos += 2
                kind = src & 0x0F
                if src & 0x20:
                    cnt = d[pos]
                    pos += 1
                    srcoffs = None
                else:
                    srcoffs = [struct.unpack_from("<h", d, pos)[0]]
                    pos += 2
                if flg & 3 != 0:
                    raise NotImplementedError("non-internal fixup target %#x" % flg)
                if flg & 0x40:
                    tobj = struct.unpack_from("<H", d, pos)[0]
                    pos += 2
                else:
                    tobj = d[pos]
                    pos += 1
                if kind == SRC_SEL16:
                    toff = 0
                elif flg & 0x10:
                    toff = struct.unpack_from("<I", d, pos)[0]
                    pos += 4
                else:
                    toff = struct.unpack_from("<H", d, pos)[0]
                    pos += 2
                if srcoffs is None:
                    srcoffs = [struct.unpack_from("<h", d, pos + 2 * j)[0] for j in range(cnt)]
                    pos += 2 * cnt
                tva = self.objs[tobj - 1].base + toff
                for so in srcoffs:
                    out.append(Fixup(pva + so, kind, tva, tobj, SRC_SIZE.get(kind, 4)))
        # a fixup straddling a page boundary is listed on both pages: dedupe
        seen, uniq = set(), []
        for f in sorted(out):
            if f.src_va not in seen:
                seen.add(f.src_va)
                uniq.append(f)
        return uniq


def main():
    le = LE(sys.argv[1] if len(sys.argv) > 1 else "dumps/disc/KKND/KKND.EXE")
    print("stub MZ @ %#x" % le.stub_off)
    print("LE header @ %#x  page size %d  pages %d  data pages @ %#x" %
          (le.le_off, le.page_size, le.num_pages, le.data_pages))
    print("entry %#x (obj %d + %#x)  stack obj %d esp %#x" %
          (le.entry_va, le.eip_obj, le.eip, le.esp_obj, le.esp))
    for o in le.objs:
        print("obj %d  base %#08x  vsize %#08x  flags %#06x  pages %d..%d" %
              (o.index, o.base, o.vsize, o.flags, o.page_index, o.page_index + o.page_count - 1))
    fx = le.fixups()
    kinds = {}
    for f in fx:
        kinds[(f.kind, f.target_obj)] = kinds.get((f.kind, f.target_obj), 0) + 1
    print("fixups: %d" % len(fx))
    for (k, t), n in sorted(kinds.items()):
        print("  src type %d -> obj %d : %d" % (k, t, n))


if __name__ == "__main__":
    main()
