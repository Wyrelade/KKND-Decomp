/* serial.c: 53 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
extern char D_000B7568[], D_000C427C[], D_000B1B70[], D_000B1B3C[];
extern u16 D_000C4292;
extern u8 D_000D1EE0;
extern int D_000C42BC, D_000C42B8, D_000D4250;
extern char D_000D4254[];
void func_0005F6A0(int, int, int, int, int);
void func_0005F410(); void func_0005F030(); void func_00029DD0(void *);
void func_0004C09C(int, char *, int); void func_0005E340(void); void func_0005F360(char *, int);

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E3C0);
int func_0005E440(void)
{
    return 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E4E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E560);
int func_0005E5D0(void) { return D_000D1EE0 == 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E5F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E6D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E700);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E7E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E8F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E9C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EA60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EAD0);
void func_0005EB70(int a) { if (a) func_0004C09C(a, D_000C427C, 0x972); }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EB90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EC30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005ECA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EE80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F030);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F0AC);
char *func_0005F2A0(void) { return D_000B7568; }

void func_0005F2B0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F2C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F4B0);
void func_0005F4E0(void) { func_0005F410(); func_0005F030(); }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F500);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F6A0);
void func_0005F7F0(int a, u8 b, int c, int d) { func_0005F6A0(a, b, c, d, 1); }

void func_0005F810(void) { func_0005F360(D_000D4254, D_000D4250); func_0005F030(); }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F830);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F880);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F8A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F930);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F9A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FA90);
int func_0005FB30(u16 x) { D_000C4292 = x; return 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FB40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FC00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FC70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FE40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FFD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000600B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000601A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00060280);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00060360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000603A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000603E0);
