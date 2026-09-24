/* mouseptr.c: 37 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "mouseptr.h"
/* decls */
int func_0002A3C0(void);
int func_000393D0(int);
int func_00039CC0(int);
int func_00039390(int);
int func_00039C80(int);
MpMob *func_0001AB70(int a, int b, int c);
void func_00019A70();
void func_000516D0(MpSprite *s);
void func_0001AA80(void *p);
extern MpNode D_000CC610;
extern void *D_000CC630;
extern char D_000BD5BC[];
void func_0001A6E0(void *a, int b);
void func_0004C09C(void *p, char *file, int line);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00015920);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015960);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000159D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015A80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015BC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00015DC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00016380);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00016990);
int func_00016CB0(int id)
{
    if (id >= 0x34 && id <= 0x39) {
        if (func_0002A3C0()) {
            if (func_000393D0(id))
                return 1;
        } else if (func_00039CC0(id)) {
            return 1;
        }
    } else {
        if (func_0002A3C0()) {
            if (func_00039390(id))
                return 1;
        } else if (func_00039C80(id)) {
            return 1;
        }
    }
    return 0;
}
void func_00016D30(void **a)
{
    void **e = a + 20;
    do {
        func_0001AA80(*a++);
    } while (a != e);
}
void func_00016D50(MpMob **a)
{
    MpMob **e = a + 20;
    do {
        *a = func_0001AB70(0x11, 0, 0);
        if (*a != 0) {
            (*a)->field_18 = 1;
            (*a)->field_68->field_10 = func_00019A70;
        }
        a++;
    } while (a != e);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00016DA0);
void func_00016F60(MpSprite *s)
{
    s32 old = s->field_10;
    s->field_10 = (old != 0x28) + 0x3a;
    func_000516D0(s);
    s->field_10 = old;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00016F90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00017020);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00017120);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000171B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00017E90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00017FF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00018D20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000190C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000193F4);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000195E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019610);
void func_00019730(MpObj *o, s32 v)
{
    if (v != o->field_20) {
        o->field_20 = v;
        func_0001A6E0(o->field_70, v);
    }
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00019750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019A30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019A70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019AE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019B50);
int func_00019C10(MpSave *d)
{
    MpNode *n = D_000CC610.field_0;
    if (n != &D_000CC610) {
        do {
            d->field_0 = n->field_8;
            d->field_4 = n->field_C;
            d->field_8 = n->field_10;
            d->field_C = n->field_14;
            d->field_10 = n->field_18;
            d->field_14 = n->field_1C;
            n = n->field_0;
            d++;
        } while (n != &D_000CC610);
    }
    return 1;
}
int func_00019C60(void)
{
    MpNode *n = D_000CC610.field_0;
    int size = 0;
    if (n != &D_000CC610) {
        do {
            n = n->field_0;
            size += 0x18;
        } while (n != &D_000CC610);
    }
    return size;
}

void func_00019C90(void)
{
    func_0004C09C(D_000CC630, D_000BD5BC, 0xbf);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00019CB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019D20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019D80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019DD0);
