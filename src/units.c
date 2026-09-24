/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* units.c: 44 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "units.h"
#include "entity.h"
/* decls */
void func_0001EBB0(EntityState *);
void func_0005FC70();
void func_0004CDC0();
void func_0005E2F0();
void func_0005E340();
void func_0005E360();
void func_0005E3C0();
void func_0005E450();
void func_0005FA50();
void func_0005FB30();
void func_0005FB40();
extern s32 D_000BDBAC;
void func_0004D2B0();
void func_0004D2D0();
void func_0004C580();
void func_00029FF0();
void func_0004D330();
void func_0004CE70();
void func_0005F810();
void func_0004CEA0();
void func_0005E110();
void func_0001AA80();
void func_00019F90();
void func_00019FD0();
void func_0001A6A0();
void func_0001EBE0(UnS *s);
void func_0004C09C();
extern s32 D_000CD960[];
extern s32 D_000CDE48[];
extern char D_000BDA44[];

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E310);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E540);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E5D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E700);
void func_0001E980(void)
{
    int i;

    for (i = 0; i < 7; i++) func_0004C09C(D_000CDE48[i], D_000BDA44, 0x142);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001E9B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001EB50);
void func_0001EB90(Entity *self, s32 arg1, s32 msg)
{
    EntityState *s = self->state;

    if (msg == 0x5DC)
        s->handler = func_0001EBB0;
}

void func_0001EBB0(EntityState *state)
{
    UnS *s = (UnS *)state;         /* the full view of the entity state block */

    s->f4->f7c = 0;
    func_0001AA80(s->f4);
    func_00019F90(s->f0);
    func_00019FD0(s->f8->fc);
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001EBE0);
void func_0001EC30(UnS *s)
{
    func_0001A6A0(s->f4, s->f28->f18, D_000CD960[s->f14]);
    s->f10 = func_0001EBE0;
    func_0001EBE0(s);
}
void func_0001EC70(Entity *self)
{
    EntityState *s = self->state;

    s->handler(s);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001EC90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001ED30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001EE10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001EEB0);
void func_0001EF30(void) { if (D_000BDBAC == 0) func_0004D2B0(); }
void func_0001EF50(void) { if (D_000BDBAC == 0) func_0004D2D0(); }
void func_0001EF70(void)
{
    if (D_000BDBAC == 0) func_0004CE70();
    else func_0005F810();
}
void func_0001EF90(s32 a, s32 b)
{
    if (D_000BDBAC == 0) func_0004CEA0(a, b);
    else func_0005E110(b);
}
void func_0001EFB0(void)
{
    func_00029FF0();
    if (D_000BDBAC == 0) func_0004D330();
}
void func_0001EFD0(void) { if (D_000BDBAC == 0) func_0004C580(); }
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001EFF0);
void func_0001F020(void)
{
    func_0004CDC0();
}

void func_0001F030(void)
{
    func_0005FA50();
}

void func_0001F040(void)
{
    func_0005FB40();
}

void func_0001F050(void)
{
    func_0005FB30();
}

void func_0001F060(s32 a)
{
    func_0005FC70(a, 0);
}

void func_0001F080(void)
{
    func_0005E450();
}

void func_0001F090(void)
{
    func_0005E2F0();
}

void func_0001F0A0(void)
{
    func_0005E340();
}

void func_0001F0B0(void)
{
    func_0005E3C0();
}

void func_0001F0C0(void)
{
    func_0005E450();
}

void func_0001F0D0(void)
{
    func_0005E360();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F0E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F110);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F140);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F1A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F1F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F250);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F2D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F370);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F3C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F410);
