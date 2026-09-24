#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "common.h"

typedef struct AirOwner { u8 _pad0[0x80]; s32 field_80; } AirOwner;
typedef struct AirGfx { u8 _pad0[0x18]; s32 field_18; } AirGfx;
typedef struct AirState {
    u8 _pad0[0x4];
    s32 field_4;
    AirOwner *field_8;
    u8 _padC[0x4];
    int (*field_10)();
    s32 field_14;
    u8 _pad18[0x10];
    AirGfx *field_28;
    u8 _pad2C[0xC];
    s32 field_38;
    s32 field_3C;
} AirState;
typedef struct AirUnit {
    u8 _pad0[0x38];
    s32 field_38;
    AirState *field_3C;
} AirUnit;

void func_0002F200();
void func_0002D050();
void func_0002EA20();
int func_0002D9C0();
void func_0002FF70();
typedef struct AirMsg { u8 _pad0[0x8]; s32 field_8; } AirMsg;
AirMsg *func_0004B5E0();
void func_0004B5C0();
void func_0004B600();
u32 func_0001A060x();
void func_0002D5D0();
void func_0002D740();
void func_0004DEC7();
void func_0001AA80();
void func_00019F90();
void func_0001A6A0(s32, s32, s32);
void func_0004B670();
u32 func_0001A060();

extern s32 D_000CFDDC;
extern s32 D_000CFE1C;
extern s32 D_000CFE68;
extern AirUnit *D_000CFE80;
extern s32 D_000CD960[];

#endif
