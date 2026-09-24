/* cflags: -s -of+ -5r -omilert -zm -zp1 */
/* netz.c: 29 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
extern char D_000B7568[], D_000C427C[], D_000B1B70[], D_000B1B3C[];
extern int D_000CFA50, D_000BDF7C, D_000CEA2C, D_000CEAEC, D_000CEAF0, D_000CE1BC, D_000CE1B8;
extern void (*D_000BDBB4)(int, char *, ...);

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F470);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F560);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F5A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F5F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F630);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F730);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F820);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F880);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F8E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F960);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001F9D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001FB90);
char *func_0001FE90(void) { return D_000B1B70; }

int func_0001FEA0(void) { (*D_000BDBB4)(0x53, D_000B1B3C); return 0xfe0013; }

int func_0001FEC0(void)
{
    return 1;
}

int func_0001FED0(void)
{
    return 0;
}

void func_0001FEE0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0001FEF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001FF20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001FF60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0001FFA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020070);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020150);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00020190);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000201D0);
void func_00020250(int a) { if (D_000CEAEC) D_000CEAF0 = a; }

int func_00020270(void) { if (D_000CEAEC == 0) return 1; return D_000CEAF0; }

int func_00020290(void) { return D_000CEA2C; }

