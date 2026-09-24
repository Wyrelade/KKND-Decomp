#ifndef BUILDING_H
#define BUILDING_H

#include "common.h"

typedef struct BuildingObj {
    u8 _pad0[0x40];
    void (*field_40)();          /* current behaviour routine */
} BuildingObj;

typedef struct BdDef {
    u8 _pad0[0x10];
    s32 f10;
    u8 _pad14[0x30];
    s32 f44;
    u8 _pad48[0xc];
    s32 f54;
} BdDef;
typedef struct BdInfo {
    s32 f0;
    s32 f4;
    s32 f8;
    s16 fc;
    s16 fe;
    s32 f10;
    u8 _pad14[4];
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
} BdInfo; /* size 0x28 */

typedef struct BdPos {
    u8 _pad0[0x70];
    s32 f70;
} BdPos;

typedef struct BdObj {
    u8 _pad0[0xc];
    s32 fc;
    s32 f10;
    s32 f14;
    BdDef *f18;
    u8 _pad1c[4];
    BdInfo *f20;
    u8 _pad24[0x1c];
    s32 f40;
    u8 _pad44[0xc];
    s32 f50;
    s32 f54;
    u8 _pad58[4];
    BdPos *f5c;
    u8 _pad60[0x30];
    s32 f90;
    s32 f94;
} BdObj;

#endif
