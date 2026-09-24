/* mission.c: 24 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
/* decls */
typedef struct { u8 _pad[0x10]; s32 field_10; s32 field_14; u8 _pad2[0x70]; s32 field_88; } MsnObj;
typedef struct { u8 _pad[0x38]; MsnObj *field_38; } MsnState;
extern s32 D_000BE7C8;
extern MsnState *D_000BE7E8;
extern s32 D_000BE8F8;
void func_0001B3E0(int, int);
void func_0002FB80(void *);
void func_0004B600(void *, int, int, int);

INCLUDE_ASM("asm/DOS/nonmatchings", func_00030E00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031230);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031270);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000312D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031500);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031560);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000315F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031660);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031740);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000317B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031870);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031A00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031A20);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031C00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031D30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031E30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00031F10);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032040);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000321D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032200);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032230);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000322E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00032340);
void func_000323B0(void *a)
{
    MsnObj *m;
    switch (D_000BE7C8) {
    case 0: case 2: case 7: case 11:
        m = D_000BE7E8->field_38;
        m->field_88 = 1;
        m->field_10 = 0x14000;
        m->field_14 = 0xF000;
        m->field_88 = 1;
        func_0001B3E0(0x140, 0xF0);
        if (D_000BE8F8 != 0) func_0002FB80(a);
        func_0004B600(a, 0x5F6, 0, 0x11);
        break;
    }
}
