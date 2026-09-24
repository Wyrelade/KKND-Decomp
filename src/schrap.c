/* schrap.c: 13 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
extern s32 D_000C3DF8;
extern s32 D_000C3DF4;

INCLUDE_ASM("asm/DOS/nonmatchings", func_00055D70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00055E80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056090);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056230);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000562E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056300);
int func_00056330(void) { return D_000C3DF8 <= 10; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056350);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056370);
int func_000563A0(void) { return D_000C3DF4 <= 30; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_000563C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000563D8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056401);
