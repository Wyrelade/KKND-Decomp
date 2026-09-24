#ifndef TOWER_H
#define TOWER_H

#include "common.h"

typedef struct TowerC {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x17];
    u8 field_27;
    u8 _pad28[0xC];
    void (*field_34)();
} TowerC;
typedef struct TowerPos { u8 _pad0[0x1C]; s32 field_1C; s32 field_20; } TowerPos;
typedef struct TowerGfx { u8 _pad0[0x14]; s32 field_14; } TowerGfx;
typedef struct TowerTgt { u8 _pad0[0x18]; s32 field_18; } TowerTgt;
typedef struct TowerUnit {
    u8 _pad0[0x10];
    s32 field_10;
    u8 _pad14[0xC];
    s32 *field_20;
    u8 _pad24[0x110];
    s32 field_134;
} TowerUnit;
typedef struct TowerOther {
    u8 _pad0[0x20];
    TowerTgt *field_20;
    u8 _pad24[0x110];
    s32 field_134;
} TowerOther;
typedef struct TowerData {
    u8 _pad0[0x4];
    TowerOther *field_4;
    u8 _pad8[0x10];
    s32 field_18;
    s32 field_1C;
    TowerUnit *field_20[1];
} TowerData;
typedef struct TowerObj {
    u8 _pad0[0xC];
    TowerC *field_C;
    s32 field_10;
    u8 _pad14[0x4];
    TowerGfx *field_18;
    u8 _pad1C[0x4];
    TowerData *field_20;
    u8 _pad24[0x1C];
    void (*field_40)();
    u8 _pad44[0x18];
    TowerPos *field_5C;
    u8 _pad60[0x20];
    s32 field_80;
    u8 _pad84[0xC];
    s32 field_90;
    u8 _pad94[0x14];
    s32 field_A8;
    s32 field_AC;
    s32 field_B0;
    u8 _padB4[0x80];
    s32 field_134;
} TowerObj;

void func_00047940();
void func_00048120();
void func_00042E30();
void func_00048D90();
void func_0001A060();
void func_0004DEC7();
void func_0001A6A0();
void func_00047DD0();
void func_00047E50();
void func_0004B670();
void func_0004B600();
void func_000514C0();
void func_0001AA80();
void func_00019F90();
void func_0001E270();
void func_00048B50();

extern s32 D_000D00C8;
extern s32 D_000CC680;
extern s32 D_000CD560[];
extern s32 D_000BDA68[];
extern s32 D_000BDA88[];

#endif
