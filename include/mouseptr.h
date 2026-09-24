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

/* Object whose 0x10 field is temporarily overridden around func_000516D0. */
typedef struct MpSprite {
    u8 _pad0[0x10];
    s32 field_10;
} MpSprite;

/* Handler block hanging off a pointer mob (field_68). */
typedef struct MpHandler {
    u8 _pad0[0x10];
    void (*field_10)();
} MpHandler;

/* Mob created by func_0001AB70 for the pointer slots. */
typedef struct MpMob {
    u8 _pad0[0x18];
    s32 field_18;
    u8 _pad1C[0x4C];
    MpHandler *field_68;
} MpMob;

#endif
