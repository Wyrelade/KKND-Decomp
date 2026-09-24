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

TankUnit *func_0001E310();
void func_00049210();
void func_0005CE50();

#endif
