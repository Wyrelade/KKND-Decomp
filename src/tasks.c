/* tasks.c: 11 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "tasks.h"
/* decls */
void func_0004C09C(void *p, char *file, int line);
extern char D_000BD6CC[];
void *func_0004C191(int size, char *file, int line);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00019E30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019EA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00019F90);
void func_00019FD0(TaskOwner *o, void *p)
{
    TaskNode *n = (TaskNode *)p - 1;
    if (n->field_4 != 0)
        n->field_4->field_0 = n->field_0;
    else
        o->field_8 = n->field_0;
    if (n->field_0 != 0)
        n->field_0->field_4 = n->field_4;
    func_0004C09C(n, D_000BD6CC, 0x191);
}
void *func_0001A010(TaskOwner *o, int size)
{
    TaskNode *n = func_0004C191(size + 8, D_000BD6CC, 0x172);
    if (n == 0)
        return n;
    n->field_0 = o->field_8;
    n->field_4 = 0;
    if (o->field_8 != 0)
        o->field_8->field_4 = n;
    o->field_8 = n;
    return n + 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A060);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A100);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A150);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A1F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001A320);
