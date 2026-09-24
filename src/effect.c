/* effect.c: 12 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
extern s32 D_000BDE9C;
extern s32 D_000BDEA0;
void func_00026F40(s32 a, s32 b);
#pragma aux func_00026F40 modify exact [eax]
extern s32 D_000BDEA4;
extern s32 D_000BDEA8[];
extern s32 D_000BDE88;
extern s32 D_000BDE8C;
extern s32 D_000BDE90;
extern s32 D_000BDE94;
void func_0001A060(void *a, u32 b, int c);
void func_00019F90(void *a);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00028040);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000281D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00028220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00028280);
void func_000282B0(void)
{
    func_00026F40(D_000BDE9C, 0);
    D_000BDEA0 = 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000282D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00028330);
s32 func_00028470(void)
{
    return D_000BDEA4;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00028480);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000284F0);
void func_00028520(void *task)
{
    int i = 0;
    s32 v;
    while ((v = D_000BDEA8[i++]) != 0) {
        D_000BDE88 = v << 8;
        func_0001A060(task, 0x80000000, 1);
    }
    D_000BDE88 = v;
    D_000BDE8C = v;
    D_000BDE90 = v;
    D_000BDE94 = v;
    func_00019F90(task);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00028580);
