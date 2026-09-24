/* files.c: 11 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
extern char D_000C4D04[];
extern char D_000B7AF8[];
void func_0001470D(int line, char *file);
extern char D_000B7AF4[];
#pragma aux func_0001470D parm routine [] modify [eax ebx ecx edx];
void func_00014BD6(int a);
int func_00085A20(int a, int b, int c, int d);
int func_00014A0C(int a, int b, int c, int d);
int func_00014976(char *a, char *b);

void func_00068B80(int a)
{
    func_0001470D(0x9c, D_000C4D04);
    func_00014BD6(a);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068BB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068CB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068D90);
int func_00068E70(int a, int b, int c)
{
    func_0001470D(0x38, D_000C4D04);
    return func_00085A20(b, 1, c, a);
}

int func_00068EB0(int a, int b, int c)
{
    func_0001470D(0x33, D_000C4D04);
    return func_00014A0C(b, 1, c, a);
}

int func_00068EF0(char *a)
{
    int r;
    func_0001470D(0x2a, D_000C4D04);
    r = func_00014976(a, D_000B7AF8);
    if (r) return r;
    return r;
}

int func_00068F20(char *a)
{
    int r;
    func_0001470D(0x20, D_000C4D04);
    r = func_00014976(a, D_000B7AF4);
    if (r)
        return r;
    return r;
}

int func_00068F50(void)
{
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068F60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00068FA0);
