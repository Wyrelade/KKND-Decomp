/* uinput.c: 17 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "uinput.h"
/* decls */
void func_0004B670(int, int, int, UiObj *);
void func_0001C9F0(char *, ...);
extern char D_000B69CC[];

INCLUDE_ASM("asm/DOS/nonmatchings", MultiPlayerControlLoop);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004A6D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004A700);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004A91C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B170);
void func_0004B1E0(UiEnt *e, int a, int msg, int unused)
{
    UiList *l = e->field_3C;
    UiNode *n;
    if (msg == 0x5E8) {
        for (n = l->next; n != (UiNode *)l; n = n->next) {
            if (n->field_8 == a) {
                n->next->prev = n->prev;
                n->prev->next = n->next;
                n->next = l->field_10;
                l->field_10 = n;
                return;
            }
        }
    }
}
void func_0004B220(UiList2 *l, int a0, int b0)
{
    volatile int b;
    volatile int a;
    UiNode2 *n;
    a = a0;
    b = b0;
    for (n = l->next; n != (UiNode2 *)l; n = n->next) {
        if (n->field_8->field_34)
            func_0004B670(l->field_14, a, b, n->field_8);
        else
            func_0001C9F0(D_000B69CC);
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B311);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B34A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B398);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B3A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B3C7);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B3E8);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B409);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B46C);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0004B510);
