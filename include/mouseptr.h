#ifndef MOUSEPTR_H
#define MOUSEPTR_H

#include "common.h"

typedef struct MpObj {
    u8 _pad0[0x20];
    s32 field_20;
    u8 _pad24[0x4C];
    void *field_70;
} MpObj;

/* Circular list node (head D_000CC610). */
typedef struct MpNode {
    struct MpNode *field_0;
    u8 _pad4[0x4];
    s32 field_8;
} MpNode;

#endif
