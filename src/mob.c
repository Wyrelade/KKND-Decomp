/* mob.c: 20 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "mob.h"
extern Mob D_000CC798;

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A3D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A470);
void func_0001A580(Mob *m)
{
    m->field_50 = 0;
    m->field_54 = 0;
    m->field_58 = 0;
    m->field_4C = 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A5B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A630);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A6A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A6E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A720);
Mob *func_0001A990(Mob *m)
{
    s32 id = m->field_C;
    if (m != &D_000CC798) {
        do {
            if (id == m->field_C)
                return m;
            m = m->field_0;
        } while (m != &D_000CC798);
    }
    return 0;
}

Mob *func_0001A9C0(s32 id)
{
    Mob *m = D_000CC798.field_0;
    if (m != &D_000CC798) {
        do {
            if (id == m->field_C)
                return m;
            m = m->field_0;
        } while (m != &D_000CC798);
    }
    return 0;
}

void func_0001A9F0(Mob *a, Mob *b)
{
    b->field_4->field_0 = b->field_0;
    b->field_0->field_4 = b->field_4;
    b->field_4 = a;
    b->field_0 = a->field_0;
    a->field_0->field_4 = b;
    a->field_0 = b;
}
void func_0001AA20(Mob *a, Mob *b)
{
    b->field_4->field_0 = b->field_0;
    b->field_0->field_4 = b->field_4;
    b->field_0 = a;
    b->field_4 = a->field_4;
    a->field_4->field_0 = b;
    a->field_4 = b;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AA80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AAF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AB70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AC40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001AD30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001ADE0);
