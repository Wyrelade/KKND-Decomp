/* vesa.c: 14 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "vesa.h"
extern s32 D_000D5248;
extern s32 D_000D5238;
extern s32 D_000D5234;
extern s32 D_000D5230;
extern s32 D_000D523C;

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068320);
void func_00068390(s32 a, s32 b, s32 c, s32 d)
{
    D_000D5238 = b;
    D_000D5234 = c;
    D_000D5230 = d;
    D_000D523C = a;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000683C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068480);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000684F0);
void func_000687F0(void)
{
    func_00083093();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068810);
void func_00068910(s32 a)
{
    D_000D5248 = a;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068920);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068960);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000689C0);
void func_00068B70(void)
{
}

