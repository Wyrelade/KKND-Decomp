/* machshop.c: 13 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "machshop.h"
/* decls */
extern s32 D_000BF610;

void func_000498A0(MachUnit *a)
{
    MachData *d = a->field_20;
    d->field_C = 0;
    func_0004B600(a->field_C, 0x601, 0, 0xca000002);
    if (d->field_C == 0 && D_000BF620 == a->field_14) {
        func_0004C163(D_000BF5EC, 0, 0x24, D_000BF5E0, 0x9d, 0x24);
        D_000BF610 = 1;
    }
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049910);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049A70);
int func_00049B80(void) { return D_000BF610 >= 5; }
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049BA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049C60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049C90);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049D50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049DB0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049E00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00049ED0);
void func_00049F60(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_00049F70);
