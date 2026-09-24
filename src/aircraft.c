/* aircraft.c: 62 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "aircraft.h"

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CD40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CED0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002CF40);
void func_0002D020(AirState *s)
{
    func_0001A6A0(s->field_4, s->field_28->field_18, D_000CD960[s->field_14]);
    s->field_10 = (int (*)())func_0002D050;
}

void func_0002D050(AirState *s)
{
    s->field_14 = s->field_8->field_80;
    func_0001A6A0(s->field_4, s->field_28->field_18, D_000CD960[s->field_14]);
}

int func_0002D080(AirUnit *a)
{
    AirState *s = a->field_3C;
    return s->field_10(s);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D0A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D120);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D1A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D1F0);
void func_0002D240(void)
{
    func_0004DEC7(D_000CFDDC);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D260);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D2D0);
void func_0002D500(void)
{
    func_0004DEC7(D_000CFE1C);
    func_0004DEC7(D_000CFE68);
}

void func_0002D520(s32 *p, s32 v)
{
    *p += v;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D530);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D5D0);
void func_0002D710(void *a, s32 *b, int c, int d, int e, int f)
{
    func_0002D5D0(a, b, *b, c, d, e, f);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D740);
void func_0002D890(void *a, s32 *b, int c, int d, int e, int f)
{
    func_0002D740(a, b, *b, c, d, e, f);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D8C0);
void func_0002D990(void)
{
}

void func_0002D9A0(void)
{
}

int func_0002D9B0(void)
{
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002D9C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DB10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DB70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DC10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DC90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DD20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DDB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DE40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DED0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DF40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DFB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E030);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E0C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E130);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E1A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E2A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E340);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E3A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E470);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E560);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E5F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E670);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E700);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E780);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E800);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E880);
void func_0002E910(void *a, int b)
{
    func_0004B670(a, b, 0, D_000CFE80);
    func_0001A060(a, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E940);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E970);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002EA20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002EAEC);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002F020);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002F070);
void func_0002F1A0(void *a)
{
    func_0002F200(a, 0, 1);
}

void func_0002F1C0(void *a)
{
    func_0002F200(a, 0, 0);
}

void func_0002F1E0(void *a)
{
    func_0002F200(a, 1, 0);
}

