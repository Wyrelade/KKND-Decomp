/* super.c: 189 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "super.h"
void func_00039190();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00032430);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032510);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032530);
void func_00032630(void)
{
    func_00049D50(0x3f, D_000CFFE0, 5);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00032650);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032680);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000327D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032800);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032B60);
void func_00032C50(int a)
{
    func_00026F40(&((SuperObj **)func_00027440(D_000B5200))[a]->field_C);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00032C80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032CC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032D10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032DA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032E70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032F50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032FB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033030);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033080);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033140);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033180);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000331C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033210);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033240);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000332A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000332E0);
void func_00033320(int a, int b, int c, int d)
{
    func_00033340(a, b, c, d, 0)->field_C |= 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00033340);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033440);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000334C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000336B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000338B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033AD0);
void func_00033B70(SuperObj *a, int b, int c)
{
    SuperSub *s = a->field_38;
    s->field_8 = 0;
    a->field_C = 0x12;
    func_00033340(s, b, 0, 0, 0);
    func_0001A6E0(s, c);
}

void func_00033BB0(SuperObj *a, int b, int c)
{
    SuperSub *s = a->field_38;
    s->field_8 = 0;
    a->field_C = c;
    func_00033340(s, 0, 0, 1, 0);
    func_0001A6E0(s, b);
}

void func_00033BF0(SuperObj *a, int b, int c)
{
    SuperSub *s = a->field_38;
    s->field_8 = 0;
    a->field_C = c;
    func_00033340(s, 0, 0, 0, 0);
    func_0001A6E0(s, b);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00033C30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033CA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033D10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033DC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033F50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00033FA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000342D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034330);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034390);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034400);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000344F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034680);
void func_00034720(void *a)
{
    func_0004D47C(D_000CFFE0, a, 5, D_000BE7BC, 0xc7e, 4);
    func_0001C9F0(D_000B50A8, D_000CFFE0[0], D_000CFFE2, D_000CFFE1, D_000CFFE3);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00034780);
s32 func_000348A0(void)
{
    return D_000CFFC8;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000348B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034980);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034A70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034B60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034BB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034C80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034D40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034D80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034E60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034F30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00034F50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035050);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035150);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000352A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000354A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000357F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035A10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035A70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035B90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035D00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035D60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00035DC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036070);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000360E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000362D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036330);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036390);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036430);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000364E0);
int func_00036620(void)
{
    return D_000BE7E0 < 0x14;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00036640);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000366A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036710);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036780);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036804);
void func_00036A20(SuperObj *a)
{
    int (*volatile f)();
    func_00033C30(a, 4, 0, 0);
    f = func_00038210;
    while (!func_000334C0(a, 0x73c, f(), 0));
}

void func_00036A70(SuperObj *a)
{
    int (*volatile f)();
    func_00033C30(a, 4, 0, 0);
    f = func_00038210;
    while (!func_000334C0(a, 0x784, f(), 0));
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00036AC0);
void func_00036B20(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00036B30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036C20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036CA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036D60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036DD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00036EC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000370C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037140);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000372F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037340);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000373C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037420);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037480);
void func_000374E0(int a)
{
    func_00037570(a, D_000B4E94, 0x6d0, 6);
}

void func_00037510(int a)
{
    func_00037570(a, D_000B4E8C, 0x6e0, 5);
}

void func_00037540(int a)
{
    func_00037570(a, D_000B4E88, 0x670, 4);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00037570);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037620);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037660);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000376C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037810);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037860);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000378E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037950);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000379D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037A50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037AE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037B70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037BC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00037F30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038050);
void func_00038090(void)
{
    D_000BE7CC = 1;
}

void func_000380B0(void)
{
    func_0001A270(0, func_000380D0, 0);
}

void func_000380D0(void *a)
{
    func_000281D0(a);
    func_00019F90(a);
}

void func_000380F0(void *a)
{
    func_00028220(a);
    func_00019F90(a);
}

void func_00038110(int a, int b, int (*c)(), int d, int e)
{
    while (!func_000334C0(a, b, c(d), e));
}

void func_00038150(int a, int b, int (*volatile c)(), int d)
{
    func_000334C0(a, b, c(), d);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038170);
void func_000381A0(int a, int b, int (*c)(), int d)
{
    while (!func_000334C0(a, b, c(), d));
}

s32 func_000381D0(void)
{
    return D_000BE7E0;
}

int func_000381E0(void)
{
    return 0;
}

int func_000381F0(void)
{
    return 0;
}

s32 func_00038200(void)
{
    return D_000BE8EC;
}

int func_00038210(void)
{
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0003821C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038244);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0003825D);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038278);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038295);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000382B1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000382B4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000382D7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000382E1);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000382FA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038354);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038356);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000383C8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000383CA);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000385E7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038620);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038644);
void func_000386F0(SuperObj *a)
{
    func_0001A6A0(a->field_5C, a->field_18->field_3C, D_000CD960[a->field_80]);
    a->field_40 = func_00038740;
    func_0001A060(a->field_C, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038740);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000387E0);
void func_00038850(SuperObj *a)
{
    func_0001A6A0(a->field_5C, a->field_18->field_3C, D_000CD960[a->field_80]);
    func_0001A060(a->field_C, 0xc0000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038890);
void func_00038910(SuperObj *a)
{
    func_00019F90(a->field_C);
    func_0001E270(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038930);
void func_000389F0(SuperObj *a)
{
    func_0001BD80(0x17, 0, D_000BE3C4, 0, 0);
    func_00051530(a);
    func_0001AA80(a->field_5C);
    func_00019F90(a->field_C);
    func_0001E270(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038A40);
void func_00038AB0(SuperObj *a)
{
    func_0001A6A0(a->field_5C, a->field_18->field_3C, D_000CD960[a->field_80]);
    a->field_40 = func_00038B00;
    func_0001A060(a->field_C, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038B00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038BE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00038C90);
void func_00038D50(SuperObj *a)
{
    func_0001A6A0(a->field_5C, a->field_18->field_34, D_000CD960[a->field_80]);
    func_0001A060(a->field_C, 0x10000000, 0);
    a->field_40 = func_00038DA0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038DA0);
void func_00038F90(SuperObj *a)
{
    func_0001A6A0(a->field_5C, a->field_18->field_38, D_000CD960[a->field_80]);
    func_0001A060(a->field_C, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00038FD0);
void func_00039040(SuperObj *a)
{
    func_0004E7D0(a);
    a->field_40 = func_00039070;
    func_0001A060(a->field_C, 0x80000000, 0x50);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00039070);
void func_000390D0(void)
{
    func_00039190();
}

void func_000390E0(SuperObj *a)
{
    func_0004E7D0(a);
    a->field_130 = 10;
    a->field_40 = func_00039120;
    func_0001A060(a->field_C, 0x80000000, 0x50);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00039120);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039190);
void func_000391F0(SuperObj *a)
{
    func_0001A6A0(a->field_5C, a->field_18->field_3C, D_000CD960[a->field_80]);
    a->field_40 = func_00039240;
    func_0001A060(a->field_C, 0x80000000, 1);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00039240);
void func_000392E0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000392F0);
void func_00039340(void *a)
{
    func_00039410(a);
    func_0004E7D0(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00039360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039390);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000393D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00039570);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000395F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000396B0);
