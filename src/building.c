/* building.c: 13 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "building.h"
/* decls */
void func_0001A060();
extern s32 D_000BB290;
void func_0004F660();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EC30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004ED80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EE10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EED0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F210);
void func_0004F2C0(BdObj *o, s32 b)
{
    if (o->f94 > 0) {
        o->f94 = 0;
        func_0001A060(o->fc, 0x80000000, 1);
        o->f94 = 0;
        o->f90 = 1;
        o->f40 = b;
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F310);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F3A0);
void func_0004F480(BdObj *o)
{
    if (D_000BB290 == 0x19 && o->f14 == 0) o->f94 = o->f18->f10 / 5 - 1;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F4C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F550);
int func_0004F640(BuildingObj *p)
{
    return p->field_40 == func_0004F660;
}

void func_0004F660(void)
{
}

