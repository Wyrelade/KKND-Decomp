/* building.c: 13 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "building.h"
void func_0004F660();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EC30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004ED80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EE10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004EED0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F210);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F2C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F310);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F3A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F480);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F4C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004F550);
int func_0004F640(BuildingObj *p)
{
    return p->field_40 == func_0004F660;
}

void func_0004F660(void)
{
}

