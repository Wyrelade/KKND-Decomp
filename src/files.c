/* files.c: 11 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "files.h"
/* decls */
FileJob *func_0001A270(int a, void (*b)(), int c);
void func_00068CB0(FileJob *j);
void *func_0004C191(u32 size, char *file, int line);
void func_0004C09C(void *p, char *file, int line);
extern char D_000C4D04[];
extern char D_000B7AF8[];
void func_0001470D(int line, char *file);
extern char D_000B7AF4[];
#pragma aux func_0001470D parm routine [] modify [eax ebx ecx edx];
void func_00014BD6(int a);
int func_00085A20(int a, int b, int c, int d);
int func_00014A0C(int a, int b, int c, int d);
int func_00014976(char *a, char *b);

void func_00068B80(int a)
{
    func_0001470D(0x9c, D_000C4D04);
    func_00014BD6(a);
}

FileLoad *func_00068BB0(int fh, FileTask *owner)
{
    FileJob *j = func_0001A270(0, (void (*)())func_00068CB0, 0x400);
    FileHdr h;
    u8 *buf;
    FileLoad *r;
    if (j == 0)
        return 0;
    func_0001470D(0x33, D_000C4D04);
    if ((u32)func_00014A0C((int)&h, 1, 8, fh) < 8)
        return 0;
    h.size = FILES_BSWAP32(h.size);
    buf = func_0004C191(h.size, D_000C4D04, 0x84);
    if (buf == 0)
        return 0;
    r = func_0004C191(0x14, D_000C4D04, 0x88);
    if (r == 0) {
        func_0004C09C(buf, D_000C4D04, 0x8a);
        return 0;
    }
    r->state = 1;
    r->fh = fh;
    r->buf = buf;
    r->size = h.size;
    r->owner = owner;
    j->field_3C = r;
    return r;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068CB0);
void *func_00068D90(int fh)
{
    FileHdr h;
    void *p;
    u32 n;
    func_0001470D(0x33, D_000C4D04);
    if ((u32)func_00014A0C((int)&h, 1, 8, fh) < 8)
        return 0;
    h.size = FILES_BSWAP32(h.size);
    p = func_0004C191(h.size, D_000C4D04, 0x46);
    if (p == 0)
        return 0;
    n = h.size;
    func_0001470D(0x33, D_000C4D04);
    if ((u32)func_00014A0C((int)p, 1, n, fh) < h.size) {
        func_0004C09C(p, D_000C4D04, 0x4b);
        return 0;
    }
    return p;
}
int func_00068E70(int a, int b, int c)
{
    func_0001470D(0x38, D_000C4D04);
    return func_00085A20(b, 1, c, a);
}

int func_00068EB0(int a, int b, int c)
{
    func_0001470D(0x33, D_000C4D04);
    return func_00014A0C(b, 1, c, a);
}

int func_00068EF0(char *a)
{
    int r;
    func_0001470D(0x2a, D_000C4D04);
    r = func_00014976(a, D_000B7AF8);
    if (r) return r;
    return r;
}

int func_00068F20(char *a)
{
    int r;
    func_0001470D(0x20, D_000C4D04);
    r = func_00014976(a, D_000B7AF4);
    if (r)
        return r;
    return r;
}

int func_00068F50(void)
{
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068F60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068FA0);
