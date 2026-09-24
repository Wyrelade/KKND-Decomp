/* tanker.c: 7 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
void func_00049690();
void func_0004E7D0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00049210);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049570);
void func_000495E0(void *e)
{
    func_00049690(e);
    func_0004E7D0(e);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049600);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049690);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049710);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049820);
