#!/usr/bin/env python3
"""Minimal OMF-386 object reader for Watcom `wcc386` output.

Reads the records the matching pipeline needs: LNAMES, SEGDEF, GRPDEF, EXTDEF, PUBDEF/LPUBDEF,
LEDATA, LIDATA (expanded), FIXUPP (THREAD + FIXUP subrecords) and COMDEF. Returns per-segment
byte images, the list of fixup locations (so compared bytes can be masked), and public symbol
offsets (so each compiled function can be cut out of its segment).

usage (CLI): omf.py file.obj    -- dump segments, publics, fixups
"""
import struct
import sys
from collections import namedtuple

Seg = namedtuple("Seg", "name cls length")
OFix = namedtuple("OFix", "seg offset loc size target_kind target selfrel target_index")

LOC_SIZE = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4, 11: 6, 13: 4}


class OMF:
    def __init__(self, path):
        self.path = path
        self.lnames = [None]
        self.segs = [None]
        self.groups = [None]
        self.exts = [None]
        self.publics = {}  # name -> (seg index, offset)
        self.data = {}     # seg index -> bytearray
        self.fixups = []
        self._parse(open(path, "rb").read())

    @staticmethod
    def _idx(b, p):
        v = b[p]
        if v & 0x80:
            return ((v & 0x7F) << 8) | b[p + 1], p + 2
        return v, p + 1

    def _parse(self, d):
        p = 0
        last_seg, last_off = None, 0
        threads = {}
        while p < len(d):
            typ = d[p]
            ln = struct.unpack_from("<H", d, p + 1)[0]
            body = d[p + 3:p + 3 + ln - 1]
            p += 3 + ln
            big = typ & 1
            t = typ & ~1
            if t == 0x96:  # LNAMES
                q = 0
                while q < len(body):
                    n = body[q]
                    self.lnames.append(body[q + 1:q + 1 + n].decode("latin1"))
                    q += 1 + n
            elif t == 0x98:  # SEGDEF
                attr = body[0]
                q = 1
                if (attr >> 5) == 0:
                    q += 3
                length = struct.unpack_from("<I" if big else "<H", body, q)[0]
                q += 4 if big else 2
                ni, q = self._idx(body, q)
                ci, q = self._idx(body, q)
                self.segs.append(Seg(self.lnames[ni], self.lnames[ci], length))
                self.data[len(self.segs) - 1] = bytearray(length)
            elif t == 0x9A:  # GRPDEF
                ni, _ = self._idx(body, 0)
                self.groups.append(self.lnames[ni])
            elif t in (0x8C, 0xB4):  # EXTDEF / LEXTDEF
                q = 0
                while q < len(body):
                    n = body[q]
                    self.exts.append(body[q + 1:q + 1 + n].decode("latin1"))
                    q += 1 + n
                    _, q = self._idx(body, q)
            elif t == 0xB0:  # COMDEF
                q = 0
                while q < len(body):
                    n = body[q]
                    self.exts.append(body[q + 1:q + 1 + n].decode("latin1"))
                    q += 1 + n
                    _, q = self._idx(body, q)
                    dt = body[q]
                    q += 1
                    for _k in range(2 if dt == 0x61 else 1):
                        lb = body[q]
                        q += 1
                        if lb == 0x81:
                            q += 2
                        elif lb == 0x84:
                            q += 3
                        elif lb == 0x88:
                            q += 4
            elif t in (0x90, 0xB6):  # PUBDEF / LPUBDEF
                gi, q = self._idx(body, 0)
                si, q = self._idx(body, q)
                if si == 0:
                    q += 2
                while q < len(body):
                    n = body[q]
                    name = body[q + 1:q + 1 + n].decode("latin1")
                    q += 1 + n
                    off = struct.unpack_from("<I" if big else "<H", body, q)[0]
                    q += 4 if big else 2
                    _, q = self._idx(body, q)
                    self.publics[name] = (si, off)
            elif t == 0xA0:  # LEDATA
                si, q = self._idx(body, 0)
                off = struct.unpack_from("<I" if big else "<H", body, q)[0]
                q += 4 if big else 2
                chunk = body[q:]
                buf = self.data[si]
                if off + len(chunk) > len(buf):
                    buf.extend(b"\0" * (off + len(chunk) - len(buf)))
                buf[off:off + len(chunk)] = chunk
                last_seg, last_off = si, off
            elif t == 0xA2:  # LIDATA
                si, q = self._idx(body, 0)
                off = struct.unpack_from("<I" if big else "<H", body, q)[0]
                q += 4 if big else 2
                out = bytearray()
                while q < len(body):
                    blk, q = self._lidata(body, q, big)
                    out += blk
                self.data[si][off:off + len(out)] = out
                last_seg, last_off = si, off
            elif t == 0x9C:  # FIXUPP
                q = 0
                while q < len(body):
                    b0 = body[q]
                    if not b0 & 0x80:  # THREAD
                        method = (b0 >> 2) & 7
                        thr = b0 & 3
                        q += 1
                        idx = None
                        if method < 4:
                            idx, q = self._idx(body, q)
                        threads[("F" if b0 & 0x40 else "T", thr)] = (method, idx)
                        continue
                    locat = (b0 << 8) | body[q + 1]
                    q += 2
                    loc = (locat >> 10) & 0xF
                    drec = locat & 0x3FF
                    fixdat = body[q]
                    q += 1
                    if fixdat & 0x80:
                        pass
                    else:
                        fm = (fixdat >> 4) & 7
                        if fm < 4:
                            _, q = self._idx(body, q)
                    if fixdat & 0x08:
                        tm, tidx = threads.get(("T", fixdat & 3), (None, None))
                    else:
                        tm = fixdat & 3
                        tidx, q = self._idx(body, q)
                    if not fixdat & 0x04:  # displacement present
                        q += 4 if big else 2
                    tm = (tm or 0) & 3
                    kind = {0: "seg", 1: "grp", 2: "ext", 3: "frame"}[tm]
                    if kind == "ext":
                        tgt = self.exts[tidx] if tidx is not None and tidx < len(self.exts) else None
                    elif kind == "seg":
                        tgt = self.segs[tidx].name if tidx else None
                    else:
                        tgt = tidx
                    selfrel = not (b0 & 0x40)  # M bit clear = self-relative (call/jmp rel32)
                    self.fixups.append(OFix(last_seg, last_off + drec, loc,
                                            LOC_SIZE.get(loc, 4), kind, tgt, selfrel, tidx))

    def _lidata(self, b, q, big):
        rep = struct.unpack_from("<I" if big else "<H", b, q)[0]
        q += 4 if big else 2
        cnt = struct.unpack_from("<H", b, q)[0]
        q += 2
        if cnt == 0:
            n = b[q]
            content = bytes(b[q + 1:q + 1 + n])
            q += 1 + n
        else:
            content = bytearray()
            for _ in range(cnt):
                blk, q = self._lidata(b, q, big)
                content += blk
        return bytes(content) * rep, q

    def seg_index(self, name):
        for i, s in enumerate(self.segs):
            if s and s.name == name:
                return i
        return None

    def functions(self):
        """[(name, seg index, offset, size)] of publics in CODE-class segments, each sized by the
        next public in the same segment or the segment end. With `wcc386 -zm` every function
        gets its own segment."""
        out = []
        for si, s in enumerate(self.segs):
            if not s or s.cls != "CODE":
                continue
            pubs = sorted((off, name) for name, (sj, off) in self.publics.items() if sj == si)
            for k, (off, name) in enumerate(pubs):
                end = pubs[k + 1][0] if k + 1 < len(pubs) else len(self.data[si])
                out.append((name, si, off, end - off))
        return out


def main():
    o = OMF(sys.argv[1])
    for i, s in enumerate(o.segs):
        if s:
            print("seg %d %-12s %-8s len %d" % (i, s.name, s.cls, s.length))
    for name, (si, off) in sorted(o.publics.items(), key=lambda x: x[1]):
        print("pub %-24s seg %d + %#x" % (name, si, off))
    for f in o.fixups:
        print("fix seg %d +%#x loc %d %s %s" % (f.seg, f.offset, f.loc, f.target_kind, f.target))
    for name, si, off, size in o.functions():
        print("func %s seg %d: %s" % (name, si, o.data[si][off:off + size].hex(" ")))


if __name__ == "__main__":
    main()
