/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* clanhall.c: 15 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
extern s32 D_000BEA74;
void func_00039D00();
void func_0004E7D0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00039760);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039870);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039A10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039B96);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039BD0);
int func_00039C00(void) { return D_000BEA74 >= 5; }
s32 func_00039C20(void) { return D_000BEA74; }
void func_00039C30(void *e)
{
    func_00039D00(e);
    func_0004E7D0(e);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039C50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039C80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039CC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039D00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039E60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039EF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039FB0);
