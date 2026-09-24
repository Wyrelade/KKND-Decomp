#ifndef CONTROLC_H
#define CONTROLC_H

#include "common.h"

typedef struct ControlcSub {
    u8 _pad0[0x18];
    s32 field_18;
} ControlcSub;

typedef struct ControlcObj {
    void (*field_0)();
    ControlcSub *field_4;
} ControlcObj;

typedef struct CcFlags {
    u8 _pad0[0xB];
    u8 field_B;
} CcFlags;

typedef struct CcSprite {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x4C];
    void *field_5C;
    u8 _pad60[8];
    CcFlags *field_68;
} CcSprite;

typedef struct CcSub28 {
    u8 _pad0[0x18];
    s32 field_18;
} CcSub28;

typedef struct CcState {
    void (*field_0)();
    s32 field_4;
    CcSprite *field_8;
    CcSprite *field_C;
    void (*field_10)(struct CcState *);
    s32 field_14;
    s32 field_18;
    u8 _pad1C[0xC];
    CcSub28 *field_28;
} CcState;

typedef struct CcEntity {
    u8 _pad0[0x3C];
    CcState *state;
} CcEntity;

#endif
