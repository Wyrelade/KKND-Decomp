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
    void (*field_10)();
    s32 field_14;
    s32 field_18;
    u8 _pad1C[0xC];
    CcSub28 *field_28;
} CcState;

typedef struct CcEntity {
    u8 _pad0[0x3C];
    CcState *state;
} CcEntity;

typedef struct CcTask {
    u8 _pad0[0x10];
    int (*field_10)(struct CcTask *);
    u8 _pad14[4];
    s32 field_18;
} CcTask;

typedef struct CcTaskEnt {
    u8 _pad0[0x3C];
    CcTask *state;
} CcTaskEnt;

typedef struct CcHook {
    void (*fn)(struct CcHook *);
    s32 field_4;
    struct CcOwner *field_8;
} CcHook;

typedef struct CcOwner {
    u8 _pad0[0x38];
    s32 field_38;
    CcHook *field_3C;
} CcOwner;

typedef struct CcTgt {
    u8 _pad0[0x14];
    s32 field_14;
    u8 _pad18[0x68];
    s32 field_80;
    u8 _pad84[0x5C];
    s32 field_E0;
    s32 field_E4;
    s32 field_E8;
    u8 _padEC[4];
    s32 field_F0;
    s32 field_F4;
} CcTgt;

typedef struct CcAimCfg {
    u8 _pad0[8];
    s32 field_8;
    u8 _padC[0xC];
    s32 field_18;
} CcAimCfg;

typedef struct CcTur {
    void (*field_0)();
    s32 field_4;
    CcTgt *field_8;
    s32 field_C;
    void (*field_10)();
    s32 field_14;
    u8 _pad18[0x10];
    CcAimCfg *field_28;
    u8 _pad2C[4];
    s32 field_30;
} CcTur;

#endif
