/* main.c: 14 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
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
INCLUDE_ASM("asm/DOS/nonmatchings", func_00010EE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00010F10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011000);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011180);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011220);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00011290);
