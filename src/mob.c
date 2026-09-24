/* mob.c: 20 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "mob.h"
/* decls */
extern s32 D_000CC7A8;
extern s16 D_000BD6D4;
extern char **D_000CC7A0;
void func_0001A470(Mob *m);
extern Mob D_000CC798;

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A3D0);
void func_0001A410(void)
{
    Mob *m;
    s16 c;
    if (D_000CC7A8 != 0) {
        m = D_000CC798.field_0;
        if (m != &D_000CC798) {
            do {
                if (D_000BD6D4 != 0 && m->field_6C != 0)
                    c = m->field_6C->field_1C & 1;
                else
                    c = 1;
                if (c)
                    func_0001A470(m);
                m = m->field_0;
            } while (m != &D_000CC798);
        }
    }
}
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
void func_0001A6A0(Mob *m, int off, int idx)
{
    m->field_4C = ((s32 **)(D_000CC7A0[m->field_C] + off))[idx];
    if (m->field_4C != 0) {
        if (*m->field_4C != 0)
            m->field_60 = *m->field_4C;
        m->field_64 = -1;
        m->field_50 = m->field_4C;
        func_0001A470(m);
    }
}
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
