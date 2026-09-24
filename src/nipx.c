/* nipx.c: 25 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
void func_00070AD0(int, int, int, u16, int, int);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00070530);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000705C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070620);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070650);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000706A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000706F0);
/* 16-bit byte swap (network order) */
u32 func_000707E0(u32 x)
{
    return (x << 8) + ((x & 0xFF00) >> 8);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00070800);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070980);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070A30);
void func_00070AA0(u16 a)
{
    func_00070AD0(0, 1, 0, a, 0, 0);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00070AD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070BF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070C30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070C70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070D10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070DF6);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070E47);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070E70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070E99);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070F59);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070F98);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00070FCE);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0007105E);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00071079);
