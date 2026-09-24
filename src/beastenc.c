/* beastenc.c: 41 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "beastenc.h"
void func_0003C110();

void func_0003BCF0(BeastObj *a)
{
    BeastSlot *d = a->field_20;
    d->field_C = 0;
    func_0004B600(a->field_C, 0x601, 0, 0xca000005);
    if (d->field_C == 0) {
        func_0004C163(D_000BF4E8, 0, 0x24, D_000BF4DC, 0xae, 0x24);
        D_000BF50C = 1;
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BD84);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BF60);
int func_0003C040(void)
{
    return D_000BF50C >= 4;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C060);
void func_0003C100(void)
{
    func_0003C110();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C110);
void func_0003C180(BeastObj *a, int b, int c, int d)
{
    if (c == 0x607) {
        a = (BeastObj *)a->field_3C;
        ((BeastState *)a)->field_20->field_4++;
        func_0005D580(a);
        return;
    }
    func_0004EED0(a, b, c, d);
}
void func_0003C1B0(BeastObj *a)
{
    a = (BeastObj *)a->field_3C;
    ((BeastState *)a)->field_20->field_4++;
    func_0005D580(a);
}

void func_0003C1D0(BeastObj *a)
{
    func_0004B600(a->field_C, 0x603, 0, 0xca00000f);
    func_0004E7D0(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C200);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C2A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C390);
void func_0003C400(BeastObj *a, int b, int msg, int d)
{
    BeastObj *s = (BeastObj *)a->field_3C;
    BeastObj *t;
    switch (msg) {
    case 0x5ed:
        func_0004F2C0(s, func_0003C1D0);
        return;
    case 0x5df:
        func_0004F210(s, d, func_0003C1D0);
        func_0005DC00(s);
        return;
    case 0x607:
        t = s;
        s = (BeastObj *)((BeastState *)s)->field_20;
        ((BeastCnt *)s)->field_4++;
        if (((BeastCnt *)s)->field_4 > 8) ((BeastCnt *)s)->field_4 = 8;
        func_0005D580(t);
        break;
    }
    func_0004EED0(a, b, msg, d);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C480);
void func_0003C4B0(BeastObj *a)
{
    func_0004B600(a->field_C, 0x604, 0, 0xca00000f);
    a->field_90 = 1;
    a->field_40 = func_0004E7D0;
    func_0001A060(a->field_C, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C500);
void func_0003C580(BeastObj *a)
{
    a->field_40 = func_0003C500;
    func_0001A060(a->field_C, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C5B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C630);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C700);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C7F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C890);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C940);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C9B0);
void func_0003CB00(BeastObj *a)
{
    func_0001C9E0(a, D_000B68F4);
    func_0001A060(a->field_C, 0x80000000, 1);
    a->field_94 = 0;
    a->field_90 = 1;
    a->field_40 = func_0003E000;
    func_00031870(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003CB60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003CBE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003CC80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003CDB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003CE30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003CEB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D0A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D170);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D320);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D3D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D660);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003D8A0);
