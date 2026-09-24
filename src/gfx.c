/* gfx.c: 26 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "vesa.h"
void func_0004DEC7();
extern s32 D_000CF184;
extern s32 D_000CF1B8;
extern char D_000B27E0[];
extern char D_000BDD88[];
extern char D_000BDDA0[];
void func_00014E42(void *a, void *b, int c, char *file, int line);
void func_00027510();
void func_0001B8C0();
void func_0006B3B0();
void func_00068B70();
void func_000205C0();
void func_000698D0();
void func_00027124();

INCLUDE_ASM("asm/DOS/nonmatchings", func_00027184);
void func_00027370(void *p)
{
    if (p != 0)
        func_00014E42(D_000BDDA0, p, 0x90, D_000BDD88, 0x106);
}

void func_000273A0(void)
{
    func_00068320(D_000B27E0);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000273C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027440);
void func_00027490(int a)
{
    func_00027510();
    func_0004DEC7(a);
    if (D_000CF184 != 0)
        func_00027510();
    func_0001B8C0();
    func_0006B3B0();
    func_00068B70();
    func_000205C0();
    func_000698D0();
}

void func_000274D0(void)
{
    if (D_000CF184 != 0)
        func_00027510();
    func_0001B8C0();
    func_0006B3B0();
    func_00068B70();
    func_000205C0();
    func_000698D0();
}

void func_00027500(void)
{
    func_0004DEC7();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00027510);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027640);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027900);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000279B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027B80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027C30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027D58);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027D7A);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027D7B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027D93);
void func_00027DB0(void)
{
    func_0004DEC7(D_000CF1B8);
    func_00027124();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00027DD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027DF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027E10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027E90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027EC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027F50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00027F90);
