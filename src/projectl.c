/* projectl.c: 18 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "projectl.h"
/* decls */
extern s32 D_000BE3C4;
void func_0001C600();
void func_0001A060();
void func_0001AA80();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00056440);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056720);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000569C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056BA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00056F40);
void func_000570B0(PjObj *o)
{
    s32 s = o->f38;
    func_0001C600(s, 0xbb, D_000BE3C4, 0);
    func_0001A060(o, 0x10000000, 0);
    func_0001AA80(s);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000570F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000571E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00057240);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000578A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000579E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00057D70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00057F00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000580D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000581F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000585C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00058630);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00058680);
