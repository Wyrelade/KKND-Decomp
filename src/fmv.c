/* fmv.c: 25 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "fmv.h"
/* decls */
extern FmvNode D_000CEB00;
extern FmvNode D_000CEB10;
extern s32 D_000CEB18;
int func_00027F50(void);
void func_000207F0(FmvNode *a);
void func_00020790(FmvNode *a);
void func_00020730(FmvNode *a, FmvNode *b);
void func_00027E10(FmvNode *a);
void func_00020A30(void);
void func_0004DEC7();
int func_000206D0(void);
s32 func_000204C0(int a, int b, int c, int d, int e, int f, int g);
void func_00060D92();
extern s32 *D_000BC908;
extern s32 D_000CEBE4;
FmvTask *func_0001A270(int a, void (*b)(), int c);
void func_00020B60();
s32 func_00020540(int a, int b, int c, int d);
void func_0001A060(int a, u32 b, int c);

INCLUDE_ASM("asm/DOS/nonmatchings", func_000202A0);
s32 func_00020440(int a, int b, int c, int d, int e, int f, int g, int h)
{
    s32 r = func_000204C0(b, c, d, e, f, g, h);
    func_0001A060(a, 0x80000000, 1);
    return r;
}
s32 func_00020480(int a, int b, int c, int d, int e)
{
    s32 r = func_00020540(b, c, d, e);
    func_0001A060(a, 0x80000000, 1);
    return r;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000204C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020540);
void func_000205C0(void)
{
    func_00060D92();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000205D0);
void func_00020600(FmvSrc *a, FmvView *b)
{
    b->field_24 = 0;
    b->field_28 = 0;
    b->field_18 = &a->field_1C;
    b->field_2C = a->field_40;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020630);
void func_00020660(void)
{
    FmvNode *n;
    for (n = D_000CEB10.next; n != &D_000CEB10; n = n->next)
        n->field_B |= 0x80;
    for (n = D_000CEB00.next; n != &D_000CEB00; n = n->next)
        n->field_B |= 0x80;
    while (func_000206D0() == 0)
        func_00020A30();
    while (func_00027F50() == 0)
        func_00020A30();
    func_0004DEC7(D_000CEB18);
}
int func_000206D0(void)
{
    if (func_00027F50() == 0)
        return 0;
    func_000207F0(&D_000CEB10);
    func_00020790(&D_000CEB10);
    func_000207F0(&D_000CEB00);
    func_00020790(&D_000CEB00);
    func_00020730(&D_000CEB00, &D_000CEB10);
    func_00027E10(&D_000CEB10);
    return 1;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020730);
void func_00020790(FmvNode *a)
{
    FmvNode *end = a->prev;
    FmvNode *p, *n;
    int done;
    do {
        p = a->next;
        done = 1;
        while (p != end) {
            n = p->next;
            if (p->key > n->key) {
                p->prev->next = n;
                n->next->prev = p;
                p->next = n->next;
                n->prev = p->prev;
                p->prev = n;
                n->next = p;
                if (n == end)
                    end = p;
                done = 0;
            } else {
                p = n;
            }
        }
        end = end->prev;
    } while (!done);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_000207F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020870);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000208F0);
void func_00020960(void)
{
}

void func_00020970(FmvObj *p)
{
    p->field_8 = 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00020980);
int func_000209A0(FmvTimer *t)
{
    t->field_0 = *D_000BC908;
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000209C0);
void func_00020A10(void)
{
    D_000CEBE4 = *D_000BC908;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00020A30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020AE0);
void func_00020B30(void)
{
    FmvTask *t = func_0001A270(0, func_00020B60, 0);
    if (t != 0)
        t->field_1C |= 1;
}

