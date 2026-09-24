#ifndef NETZ_H
#define NETZ_H

#include "common.h"

typedef struct NzView {
    u8 _pad0[0x18];
    s32 field_18;
    s32 field_1C;
} NzView;

typedef struct NzPos {
    u8 _pad0[0xC];
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
} NzPos;

typedef struct NzVec {
    s32 x;
    s32 y;
    s32 z;
} NzVec;

typedef struct NzFlags {
    u8 _pad0[0xB];
    u8 field_B;
} NzFlags;

typedef struct NzLink {
    struct NzLink *next;
    struct NzLink *prev;
    NzFlags *obj;
} NzLink;

#endif
