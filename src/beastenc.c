/* beastenc.c: 41 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "beastenc.h"
void func_0003C110();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BCF0);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C180);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003C400);
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
