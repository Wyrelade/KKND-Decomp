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

typedef struct TbOff {
    s32 field_0;
    s32 field_4;
    u8 _pad8[4];
    s32 field_C;
} TbOff;

typedef struct TbSrc {
    u8 _pad0[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    u8 _pad1C[0x38];
    TbOff *field_54;
} TbSrc;

typedef struct TbDst {
    u8 _pad0[0x18];
    s32 field_18;
    u8 _pad1C[4];
    void *field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
} TbDst;

typedef struct TbSlots {
    u8 _pad0[8];
    s32 field_8;
    s32 field_C;
} TbSlots;

typedef struct TbEntry {
    struct TbEntry *next;
    struct TbEntry *prev;
    s32 field_8;
    u8 _padC[0xC];
    s32 field_18;
    TbSlots *field_1C;
    u8 _pad20[4];
    s32 field_24;
} TbEntry;

typedef struct TbList {
    u8 _pad0[0xC];
    s32 field_C;
} TbList;

typedef struct TbFx {
    u8 _pad0[0x10];
    void (*field_10)();
} TbFx;

typedef struct TbMob {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[8];
    s32 field_18;
    u8 _pad1C[0x44];
    s32 field_60;
    u8 _pad64[4];
    TbFx *field_68;
} TbMob;

typedef struct TbBld {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x30];
    void (*field_40)();
    u8 _pad44[0x18];
    TbMob *field_5C;
} TbBld;

typedef struct TbWidget {
    u8 _pad0[0x18];
    s32 field_18;
    s32 field_1C;
} TbWidget;

#endif
