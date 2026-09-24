#ifndef TOOLBARS_H
#define TOOLBARS_H

#include "common.h"

typedef struct TbObj {
    u8 _pad0[0xC];
    s32 field_C;
    s32 field_10;
    u8 _pad14[0xC];
    s32 field_20;
    u8 _pad24[0x38];
    s32 field_5C;
    u8 _pad60[0x54];
    s32 field_B4;
} TbObj;

typedef struct TbSub8 {
    u8 _pad0[0x14];
    u8 field_14[1];
} TbSub8;

typedef struct TbGlobal {
    u8 _pad0[8];
    TbSub8 *field_8;
} TbGlobal;

#endif
