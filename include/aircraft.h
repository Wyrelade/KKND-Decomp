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

typedef struct AirSub68 { u8 _pad0[0x10]; void (*field_10)(); } AirSub68;
typedef struct AirPar {
    u8 _pad0[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    u8 _pad1C[0x6C];
    s32 field_88;
} AirPar;
typedef struct AirSub {
    u8 _pad0[0x8];
    AirPar *field_8;
    u8 _padC[0x4];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    u8 _pad1C[0x4C];
    AirSub68 *field_68;
    u8 _pad6C[0x1C];
    s32 field_88;
} AirSub;
typedef struct AirObj {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x28];
    AirSub *field_38;
    AirSub *field_3C;
} AirObj;
AirSub *func_0001AB70();
void func_0002C740();
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

void func_0002E970();
void func_0006C530();
void func_00033340();
void func_0004B600();
void func_000301B0();
void func_00030090();
void func_000523F0();
extern s32 D_000CFE70;
extern s32 D_000BB898;
extern s32 D_000BE7CC;
extern s32 D_000BB284;
extern s32 D_000CFFD8;
typedef struct AirTgt { u8 _pad0[0x134]; s32 field_134; } AirTgt;
typedef struct AirNode { struct AirNode *next; struct AirNode *prev; AirTgt *field_8; } AirNode;
typedef struct AirKey { u8 _pad0[0x10]; s32 field_10; } AirKey;
extern AirNode *D_000CFDDC;
extern AirNode *D_000CFDE0;
extern AirNode D_000CFDD0;
AirNode *func_0004DDF1();
void func_0002FB80();
void func_0001A6E0();
extern s32 D_000CFE1C;
extern s32 D_000CFE68;
extern AirUnit *D_000CFE80;
extern s32 D_000CD960[];

#endif
