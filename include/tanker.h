#ifndef TANKER_H
#define TANKER_H

#include "common.h"

typedef struct TankHdr { u8 _pad0[0xC]; s32 field_C; } TankHdr;
typedef struct TankUnit {
    u8 _pad0[0xC];
    TankHdr *field_C;
    u8 _pad10[0x2C];
    struct TankUnit *field_3C;
    void (*field_40)();
    u8 _pad44[0xEC];
    s32 field_130;
    u8 _pad134[0x4];
    s32 field_138;
} TankUnit;

typedef struct TankData { u8 _pad0[0x4]; s32 field_4; u8 _pad8[0x8]; s32 field_10; } TankData;
typedef struct TankBld { u8 _pad0[0x14]; s32 field_14; u8 _pad18[0x8]; TankData *field_20; } TankBld;
extern s32 D_000BF620;
extern s32 D_000BF610;
extern s32 D_000BF5EC[];
int func_0002A8E0();
TankUnit *func_0001E310();
void func_00049210();
void func_0005CE50();

#endif
