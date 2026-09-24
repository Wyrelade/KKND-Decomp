/* cflags: -s -of+ -5r -omilert -zm -zp1 */
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AD50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003ADC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AE30);
void func_0003AE80(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AE90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003AF50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B040);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B080);
void func_0003B120(void)
{
    func_0003B130();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B130);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B1B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B460);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B4D0);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003B840);
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003BC80);
