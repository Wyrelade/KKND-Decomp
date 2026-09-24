/* outpost.c: 48 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "outpost.h"
#include "entity.h"
void func_0003B130();
void func_0004E7D0();

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A060);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A170);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A300);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A3D2);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A419);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A46F);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A496);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A4B2);
int func_0003A4F0(void)
{
    return D_000BEB1C >= 5;
}

s32 func_0003A510(void)
{
    return D_000BEB1C;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A520);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A5A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A5E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A660);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003A900);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AA30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AA60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AAA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AB10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AC90);
int func_0003AD50(OutWp *a)
{
    if (D_000BB290 == 8) {
        if (a->i < 0x12) {
            a->x = D_000BF3D4[a->i].x << 8;
            a->y = D_000BF3D4[a->i].y << 8;
            return 1;
        }
    } else if (a->i < 0xf) {
        a->x = D_000BF464[a->i].x << 8;
        a->y = D_000BF464[a->i].y << 8;
        return 1;
    }
    return 0;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003ADC0);
void func_0003AE30(OutUnit *a)
{
    if (a->field_138 == 0) {
        func_000514C0(a, a->field_AC, a->field_B0, a->field_A8);
        a->field_5C->field_1C = 0;
        a->field_5C->field_20 = 0;
        a->field_40 = func_0003AE80;
    }
}
void func_0003AE80(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AE90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AF50);
void func_0003B040(OutState *a)
{
    OutData *d = a->field_20;
    if (d->field_8) {
        func_0002D530(&d->field_8, 0);
        d->field_8 = 0;
    }
    func_0004E7D0(a);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B080);
void func_0003B120(void)
{
    func_0003B130();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B130);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B1B0);
void func_0003B460(OutBld *a)
{
    OutTask *s = a->field_3C;
    if (!s) {
        s = func_0001A010(a, 0x20);
        if (s) {
            a->field_3C = s;
            s->field_4 = 0;
            s->field_8 = 0;
            s->field_10 = a->field_38->field_8;
            s->field_C = 0;
            s->field_18 = a->field_38;
            s->field_0 = func_0003B4D0;
            s->field_1C = a;
            a->field_C = 0xca000013;
            a->field_34 = func_0003B6A0;
        }
    }
    s->field_0(s);
}
void func_0003B4D0(OutState *a)
{
    s32 t = a->field_10->field_90;
    if (t || a->field_C) a->field_0 = func_0003B660;
    else if (--a->field_4 <= 0) {
        a->field_0 = func_0003B510;
        a->field_4 = 8;
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B510);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B660);
void func_0003B6A0(Entity *self, s32 arg1, s32 msg)
{
    EntityState *s = self->state;

    if (msg == 0x609)
        s->field_C = 1;
}

void func_0003B6C0(void)
{
    func_0004E7D0();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B6D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B790);
void func_0003B840(OutUnit *a)
{
    OutUnit *u = a->field_3C;
    if (!u) {
        u = func_0001E310(a);
        u->field_C->field_34 = func_0003B8B0;
        func_0004F3A0(u, 2, func_0003B750, func_0003B790);
        if (u->field_5C->field_70 == 0) func_0004F4C0(u, func_0003B6D0);
        else u->field_40 = func_0003B6D0;
    }
    u->field_40(u);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B8B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B9F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BA80);
void func_0003BB10(void *a)
{
    func_0003BB30(a);
    func_0004E7D0(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BB30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BBB0);
void func_0003BC80(OutUnit *a)
{
    OutUnit *u = a->field_3C;
    if (!u) {
        u = func_0001E310(a);
        u->field_C->field_34 = func_0003BD84;
        func_0004F3A0(u, 2, func_0003BB30, func_0003BBB0);
        func_0003BCF0(u);
        if (u->field_5C->field_70 == 0) func_0004F4C0(u, func_0003BA80);
        else u->field_40 = func_0003BA80;
    }
    u->field_40(u);
}
