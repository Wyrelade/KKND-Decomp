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
void func_0002D1A0(AirKey *a)
{
    s32 k = a->field_10;
    AirNode *n;
    for (n = D_000CFDD0.next; n != &D_000CFDD0; n = n->next) {
        if (k == n->field_8->field_134) {
            n->next->prev = n->prev;
            n->prev->next = n->next;
            n->next = D_000CFDE0;
            D_000CFDE0 = n;
            return;
        }
    }
}
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
int func_0002DB10(AirUnit *a)
{
    int r = 1;
    u32 f;
    AirMsg *m;
    do {
        f = func_0001A060(a, 0x50000000, 0);
        if (!(f & 0x40000000)) break;
        while ((m = func_0004B5E0(a)) != 0) {
            if (m->field_8 == 0x5f8) r = 0;
            func_0004B5C0(m);
        }
    } while (!r && !(f & 0x10000000));
    return r;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DB70);
void func_0002DC10(AirUnit *a)
{
    s32 s;
    func_0002E970(a, 0xda000007, 0x64, 0x67, 3);
    func_00033340(a->field_38, 0, 1, 1, 0);
    if (func_0002D9C0(a, 0x648, 1, 1)) func_0002FB80(a);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002DC90(AirUnit *a)
{
    int r;
    s32 s;
    func_0002E970(a, 0xda000006, -0x1e, 0x67, 3);
    func_00033340(a->field_38, 0, 0, 1, 0);
    do {
        r = func_0002D9C0(a, 0x630, 2, 1);
        func_0004B670(a, 0x5e8, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002DD20(AirUnit *a)
{
    int r;
    s32 s;
    func_0002E970(a, 0xda000006, -0x50, 0x67, 3);
    func_00033340(a->field_38, 0, 0, 1, 0);
    do {
        r = func_0002D9C0(a, 0x63c, 2, 1);
        func_0004B670(a, 0x5eb, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002DDB0(AirUnit *a)
{
    int r;
    s32 s;
    func_0006C530(a);
    func_0002E970(a, 0xda000007, 0x14, 0x67, 3);
    func_00033340(a->field_38, 0, 0, 1, 0);
    do {
        r = func_0002D9C0(a, 0x654, 1, 1);
        if (r) func_0004B670(a, 0x60d, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002DE40);
void func_0002DED0(AirUnit *a)
{
    int r;
    s32 s;
    func_0002EA20(a, 0xda000001, -0x82, 0x99, 3);
    do {
        r = func_0002D9C0(a, 0x2dc, 2, 0);
        func_0004B670(a, 0x5e8, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002DF40(AirUnit *a)
{
    int r;
    s32 s;
    func_0002EA20(a, 0xda000001, -0xb4, 0x99, 3);
    do {
        r = func_0002D9C0(a, 0x2e8, 2, 0);
        func_0004B670(a, 0x5eb, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002DFB0(AirUnit *a)
{
    int r;
    s32 s;
    func_0006C530(a);
    func_0002EA20(a, 0xda000001, -0x50, 0x99, 3);
    do {
        r = func_0002D9C0(a, 0x324, 1, 0);
        if (r) func_0004B670(a, 0x60d, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E030);
void func_0002E0C0(AirUnit *a)
{
    int r;
    s32 s;
    func_0002EA20(a, 0xda000001, -0x82, 0x99, 3);
    do {
        r = func_0002D9C0(a, 0x2dc, 2, 0);
        func_0004B670(a, 0x5e8, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E130(AirUnit *a)
{
    int r;
    s32 s;
    func_0002EA20(a, 0xda000001, -0xb4, 0x99, 3);
    do {
        r = func_0002D9C0(a, 0x2e8, 2, 0);
        func_0004B670(a, 0x5eb, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E1A0(AirUnit *a)
{
    int r;
    s32 s;
    func_0006C530(a);
    func_0002EA20(a, 0xda000001, -0x50, 0x99, 3);
    do {
        r = func_0002D9C0(a, 0x318, 1, 0);
        if (r) func_0004B670(a, 0x5f4, 0, D_000CFE70);
    } while (r);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E2A0);
void func_0002E340(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000003, 0, 0x78, 1);
    if (func_0002D9C0(a, 0x300, 1, 0)) func_0002FF70(0);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E3A0(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000003, -0x5a, 0x78, 1);
    if (func_0002D9C0(a, 0x30c, 1, 0)) D_000BB284 = 3;
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E410(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000003, 0, 0x78, 1);
    if (func_0002D9C0(a, 0x300, 1, 0)) func_00030090(0);
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002E470);
void func_0002E560(AirUnit *a)
{
    s32 s;
    s16 v = D_000BB898 ? 0xa2 : 0x72;
    func_0002EA20(a, 0xda000002, -0x5c, v, 7);
    if (func_0002D9C0(a, 0x33c, 0, 0)) {
        func_0004B670(a, 0x5f3, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E5F0(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000002, -0x5c, 0x8a, 6);
    if (func_0002D9C0(a, 0x36c, 0, 0)) {
        func_0004B670(a, 0x5f7, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E670(AirUnit *a)
{
    s32 s;
    s16 v = D_000BB898 ? 0x72 : 0x5a;
    func_0002EA20(a, 0xda000002, -0x5c, v, 5);
    if (func_0002D9C0(a, 0x348, 0, 0)) {
        func_0004B670(a, 0x5f8, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E700(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000002, -0x5c, 0x5a, 4);
    if (func_0002D9C0(a, 0x354, 0, 0)) {
        func_0004B670(a, 0x5f6, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E780(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000002, -0x5c, 0x42, 3);
    if (func_0002D9C0(a, 0x384, 0, 0)) {
        func_0004B670(a, 0x5e3, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E800(AirUnit *a)
{
    s32 s;
    func_0002EA20(a, 0xda000002, -0x5c, 0x2a, 2);
    if (func_0002D9C0(a, 0x378, 0, 0)) {
        func_0004B670(a, 0x5e5, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E880(AirUnit *a)
{
    s32 s;
    s16 v = D_000BB898 ? 0x12 : 0x42;
    func_0002EA20(a, 0xda000002, -0x5c, v, 1);
    if (func_0002D9C0(a, 0x360, 0, 0)) {
        func_0004B670(a, 0x5f4, 0, D_000CFE80);
        func_0001A060(a, 0x80000000, 1);
    }
    s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
void func_0002E910(void *a, int b)
{
    func_0004B670(a, b, 0, D_000CFE80);
    func_0001A060(a, 0x80000000, 1);
}

void func_0002E940(AirUnit *a)
{
    s32 s = a->field_38;
    func_0001AA80(a->field_3C);
    func_0001AA80(s);
    func_00019F90(a);
}
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

