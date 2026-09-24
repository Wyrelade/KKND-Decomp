/* machshop.c: 13 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
extern s32 D_000BF610;

INCLUDE_ASM("asm/DOS/nonmatchings", func_000498A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049910);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049A70);
int func_00049B80(void) { return D_000BF610 >= 5; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049BA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049C60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049C90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049D50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049DB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049E00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049ED0);
void func_00049F60(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00049F70);
