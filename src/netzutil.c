/* netzutil.c: 35 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "netzutil.h"
extern NetzGame *D_000CFB3C;
extern NetzEvent *D_000BDF7C;
extern NetzPacket *D_000BDF74;
extern char D_000B2FE0[];
extern char D_000B2EB0[];
extern void (*D_000BDBB4)(int, char *, ...);
int func_00029A00(NetzEvent *);
int func_000299A0(NetzEvent *);
void func_00050DF0(void);
void func_0004B670(int, int, int, int);
int func_000267D0(void);
int func_0002A070(void);
void func_0001F250(int);
int func_00029EC0(int);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029650);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000296E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000297B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029860);
void func_00029910(void)
{
    if (D_000BDF7C)
        do
            func_00029A00(D_000BDF7C);
        while (D_000BDF7C);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029940);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029970);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000299A0);
int func_00029A00(NetzEvent *e)
{
    if (e->field_0 == 0) {
        D_000BDBB4(0x45, D_000B2FE0, e);
        return 0xFE000B;
    }
    return func_000299A0(e);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029A30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029AC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029BD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029C40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029CE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029D30);
void func_00029DD0(NetzPacket *p)
{
    if (p->field_0 == 0) {
        D_000BDBB4(0x45, D_000B2EB0, p);
    } else {
        NetzPacket *t = D_000BDF74;
        p->field_0 = 0;
        D_000BDF74 = p;
        p->field_4 = t;
    }
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029E10);
int func_00029E90(void) { int i; for (i = 0; i < 8; i++) { func_0001F250(i); func_00029EC0(i); } return 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_00029EC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029F00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029FB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00029FF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A020);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A070);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A0A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A120);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A190);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A2C0);
void func_0002A330(void)
{
}

void func_0002A340(void)
{
}

void func_0002A350(void)
{
    func_00050DF0();
    func_0004B670(0, 0x60C, 0, D_000CFB3C->field_8);
}

void func_0002A380(void)
{
    if (func_000267D0() || !func_0002A070())
        func_0004B670(0, 0x5EA, 0, D_000CFB3C->field_8);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0002A3C0);
