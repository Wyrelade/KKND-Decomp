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
typedef struct TowerPos { u8 _pad0[0x10]; s32 field_10; s32 field_14; s32 field_18; s32 field_1C; s32 field_20; u8 _pad24[0x64]; s32 field_88; } TowerPos;
typedef struct TowerGfx { u8 _pad0[0x14]; s32 field_14; u8 _pad18[0x4]; s32 field_1C; u8 _pad20[0x14]; s32 field_34; u8 _pad38[0x4]; s32 field_3C; } TowerGfx;
typedef struct TowerTgt { u8 _pad0[0x18]; s32 field_18; } TowerTgt;
typedef struct TowerUnit {
    u8 _pad0[0x10];
    s32 field_10;
    u8 _pad14[0xC];
    s32 *field_20;
    u8 _pad24[0x110];
    s32 field_134;
} TowerUnit;
typedef struct TowerOff { u8 _pad0[0x4]; s32 field_4; s32 field_8; } TowerOff;
typedef struct TowerOther {
    u8 _pad0[0x20];
    TowerTgt *field_20;
    u8 _pad24[0x38];
    struct TowerPos *field_5C;
    u8 _pad60[0x14];
    TowerOff *field_74;
    u8 _pad78[0xBC];
    s32 field_134;
} TowerOther;
typedef struct TowerData {
    s32 field_0;
    TowerOther *field_4;
    TowerOther *field_8;
    TowerOther *field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    TowerUnit *field_20[1];
} TowerData;
typedef struct TowerObj {
    u8 _pad0[0xC];
    TowerC *field_C;
    s32 field_10;
    s32 field_14;
    TowerGfx *field_18;
    struct TowerLink *field_1C;
    TowerData *field_20;
    u8 _pad24[0x1C];
    void (*field_40)();
    u8 _pad44[0x4];
    void (*field_48)();
    u8 _pad4C[0x10];
    TowerPos *field_5C;
    u8 _pad60[0x20];
    s32 field_80;
    u8 _pad84[0xC];
    s32 field_90;
    s32 field_94;
    u8 _pad98[0x10];
    s32 field_A8;
    s32 field_AC;
    s32 field_B0;
    u8 _padB4[0x2C];
    s32 field_E0;
    struct TowerOther *field_E4;
    u8 _padE8[0x8];
    s32 field_F0;
    u8 _padF4[0xC];
    s32 field_100;
    s32 field_104;
    u8 _pad108[0x2C];
    s32 field_134;
    s32 field_138;
} TowerObj;
typedef struct TowerNew { u8 _pad0[0x70]; void *field_70; u8 _pad74[0xC]; s32 field_80; } TowerNew;
typedef struct TowerP54 { s32 field_0; s32 field_4; u8 _pad8[0x4]; s32 field_C; } TowerP54;
typedef struct TowerSrc {
    u8 _pad0[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    u8 _pad1C[0x38];
    TowerP54 *field_54;
} TowerSrc;
typedef struct TowerDst {
    u8 _pad0[0x18];
    s32 field_18;
    u8 _pad1C[0x4];
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2C;
} TowerDst;
typedef struct TowerFlagB { u8 _pad0[0xB]; u8 field_B; } TowerFlagB;
typedef struct TowerLObj { u8 _pad0[0x10]; s32 field_10; s32 field_14; u8 _pad18[0x50]; TowerFlagB *field_68; } TowerLObj;
typedef struct TowerLNode { struct TowerLNode *next; u8 _pad4[0x4]; TowerLObj *field_8; } TowerLNode;
extern TowerLNode D_000D00B0;
typedef struct TowerL4 { u8 _pad0[0x7C]; s32 field_7C; } TowerL4;
typedef struct TowerLink { s32 field_0; TowerL4 *field_4; u8 _pad8[0x8]; void (*field_10)(); } TowerLink;
typedef struct TowerNew2 { u8 _pad0[0x18]; s32 field_18; } TowerNew2;
TowerNew2 *func_00055C30();
void func_000464A0();
void func_000470D0();
void func_00047200();
void func_00047210();
void func_00046CA0();
void func_00051480();
void func_0002D520();
void func_0005D990();
void func_00048BF0();
extern s32 D_000BDA54;
extern s32 D_000CFB40[];
void func_00048E70();
void func_00048D10();
void func_00042658();
void func_00048C90();
void func_00048F40();
void func_00048A10();
void func_000489B0();
TowerOther *func_00048A70();
int func_0001DE10();
TowerNew *func_0001E1F0();
void func_00051530();
void func_0001BD80();
void func_0003DBD0();
void func_00047760();
void func_00047D30();
extern s32 D_000BF620;
extern s32 D_000CD960[];
extern s32 D_000BE3C4;
extern s32 D_000CE1CC;
extern s32 D_000CE1D0;
extern s32 D_000BDE74;
extern u8 D_000BF5A8[];
extern u8 D_000BF57C[];

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
