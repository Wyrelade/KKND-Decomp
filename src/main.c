/* main.c: 14 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
void func_0001470D(int line, char *file);
#pragma aux func_0001470D parm routine [] modify [eax ebx ecx edx];
void func_00014D18(int line, char *file);
#pragma aux func_00014D18 parm routine [] modify [eax ebx ecx edx];
void func_00014D9B(char *, char *, ...);
#pragma aux func_00014D9B modify [eax ebx ecx edx];
int func_00014976(char *a, char *b);
int func_00014A0C(void *buf, int size, int n, int fh);
void func_00014BD6(int fh);
extern char D_000B98D0[];
extern char D_000B0010[];
extern char D_000B0014[];
extern char D_000B0020[];
extern char D_000CC44C[];
#include "main.h"
extern MainGlobal *D_000B98D8;
void func_00010010(int);
void func_0001A410(void);
void func_0001A720(void);
void func_0001AEB0(void);
void func_0001B000(void);
void func_0001B940(void);
void func_0001C570(void);
void func_0001F560(int a);
void func_00019EA0(void);
void func_0001FF20(void);
void func_000202A0(void);
void func_000206D0(void);
void func_00020A30(void);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00010010);
void func_000100C0(u8 arg0)
{
    func_00010010(arg0);
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000100E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00010150);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00010B40);
void func_00010DD0(void)
{
    func_0001A410();
    func_0001A720();
    func_0001AEB0();
    func_0001B000();
    func_0001B940();
    func_0001C570();
    func_0001F560(0xffff);
    func_00019EA0();
    func_0001FF20();
    func_000202A0();
    func_000206D0();
    func_00020A30();
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00010E20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00010EB0);
void func_00010EE0(int a, MainRect *r)
{
    MainGlobal *g = D_000B98D8;
    r->field_24 = g->field_8->field_24;
    r->field_28 = g->field_8->field_28;
    r->field_2C = 0xfffff;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00010F10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011000);
int func_00011180(void)
{
    u8 drive;
    int fh;
    func_0001470D(0xa1, D_000B98D0);
    fh = func_00014976(D_000B0014, D_000B0010);
    if (fh == 0)
        return 0;
    func_0001470D(0xa4, D_000B98D0);
    func_00014A0C(&drive, 1, 1, fh);
    func_0001470D(0xa5, D_000B98D0);
    func_00014BD6(fh);
    func_00014D18(0xa6, D_000B98D0);
    func_00014D9B(D_000CC44C, D_000B0020, drive);
    return 1;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011290);
