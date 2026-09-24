/* ini.c: 49 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "ini.h"
extern char D_000D5300[];
extern char D_000D5270[];
extern s32 D_000D5394;
extern s32 D_000D6DFC;
extern IniLine *D_000D53B0;
extern s32 D_000D6E20;
int func_00068F60();
void func_0004DEC7();
extern s32 D_000D6DEC;
extern s32 D_000D6DE0;
extern s32 D_000D6DE4;
extern s32 D_000D6DF0;
extern IniHook D_000D6E18;

INCLUDE_ASM("asm/DOS/nonmatchings", func_00068FE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069160);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000691D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069240);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069498);
char *func_00069630(void)
{
    return D_000D5300;
}

char *func_00069640(void)
{
    return D_000D5270;
}

s32 func_00069650(void)
{
    return D_000D5394;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00069660);
char *func_000696A0(void)
{
    return D_000D53B0->field_0;
}

void func_000696B0(void)
{
    IniLine *p = D_000D53B0;
    if (p->field_8 != 0)
        D_000D53B0 = p->field_8;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000696D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069750);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000697A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069810);
int func_00069860(void)
{
    return func_00068F60() != 0;
}

int func_00069880(void)
{
    return *D_000D53B0->field_0 == '[';
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_000698A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000698D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069980);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000699E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069A2B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069A5B);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069AC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069CE0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069ED0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00069F50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006A210);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006A7A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006A9B0);
void func_0006ABA0(s32 a, s32 b, s32 c, s32 d)
{
    D_000D6DEC = b;
    D_000D6DE0 = c;
    D_000D6DE4 = d;
    D_000D6DF0 = a;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006ABC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006AC60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006ADC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006ADF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006AE50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006AEC0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006AEF0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006AF20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B090);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B1B0);
s32 func_0006B2B0(void)
{
    return D_000D6DFC;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B2C0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B2DF);
void func_0006B3B0(void)
{
    func_0004DEC7(D_000D6E20);
}

void func_0006B3D0(void)
{
    IniHook *h = D_000D6E18.field_0;
    if (h != &D_000D6E18) {
        do {
            if (h->field_14 != 0)
                h->field_14();
            h = h->field_0;
        } while (h != &D_000D6E18);
    }
}

int func_0006B400(void)
{
    IniHook *h = D_000D6E18.field_0;
    if (h != &D_000D6E18) {
        do {
            if (h->field_C != 0)
                if (h->field_C() == 0)
                    return 0;
            h = h->field_0;
        } while (h != &D_000D6E18);
    }
    return 1;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B440);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0006B4E0);
