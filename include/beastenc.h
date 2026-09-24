#ifndef BEASTENC_H
#define BEASTENC_H

#include "common.h"

typedef struct BeastCnt { u8 _pad0[0x4]; s32 field_4; } BeastCnt;
typedef struct BeastState { u8 _pad0[0x20]; BeastCnt *field_20; } BeastState;
typedef struct BeastFlagB { u8 _pad0[0xB]; u8 field_B; } BeastFlagB;
typedef struct BeastLnk2 { u8 _pad0[0x68]; BeastFlagB *field_68; } BeastLnk2;
typedef struct BeastLnk { u8 _pad0[0x4]; BeastLnk2 *field_4; } BeastLnk;
typedef struct BeastPos {
    u8 _pad0[0x10];
    s32 field_10;
    s32 field_14;
    u8 _pad18[0x4];
    s32 field_1C;
    s32 field_20;
    u8 _pad24[0x4C];
    s32 field_70;
    u8 _pad74[0x14];
    s32 field_88;
} BeastPos;
typedef struct BeastHdr { u8 _pad0[0xC]; s32 field_C; u8 _pad10[0x24]; void (*field_34)(); } BeastHdr;
typedef struct BeastGfx { u8 _pad0[0x10]; s32 field_10; u8 _pad14[0x20]; s32 field_34; } BeastGfx;
typedef struct BeastTgt { u8 _pad0[0x10]; s32 field_10; s32 field_14; u8 _pad18[0x11C]; s32 field_134; } BeastTgt;
typedef struct BeastSlot { BeastTgt *field_0; } BeastSlot;
typedef struct BeastMsg { s32 field_0; BeastTgt *field_4; } BeastMsg;
typedef struct BeastObj {
    u8 _pad0[0x8];
    s32 field_8;
    BeastHdr *field_C;
    u8 _pad10[0x4];
    s32 field_14;
    BeastGfx *field_18;
    BeastLnk *field_1C;
    BeastSlot *field_20;
    u8 _pad24[0x18];
    BeastState *field_3C;
    void (*field_40)();
    u8 _pad44[0x4];
    void (*field_48)();
    u8 _pad4C[0x10];
    BeastPos *field_5C;
    u8 _pad60[0x20];
    s32 field_80;
    u8 _pad84[0xC];
    s32 field_90;
    s32 field_94;
    s32 field_98;
    s32 field_9C;
    u8 _padA0[0x40];
    s32 field_E0;
    BeastTgt *field_E4;
    s32 field_E8;
    u8 _padEC[0x4];
    s32 field_F0;
    u8 _padF4[0x40];
    s32 field_134;
    s32 field_138;
    u8 _pad13C[0x16B];
    s16 field_2A7;
    BeastTgt *field_2A9;
    s32 field_2AD;
} BeastObj;

void func_0005D580();
void func_0003C500();
void func_0001A060();
void func_0004B600();
void func_0004E7D0();
void func_0001C9E0(void *, char *, ...);
void func_0003E000();
void func_00031870();

BeastObj *func_0001E310();
void func_0004F3A0();
void func_0004F4C0();
void func_0004F710();
void func_0004F2C0();
void func_0004F210();
void func_0005DC00();
void func_0004EED0();
void func_0003C180();
void func_0003C060();
void func_0003C400();
void func_0003C200();
void func_0003C1D0();
void func_0004EB90();
void func_0004E990();
void func_000515E0();
BeastTgt *func_00047540();
void func_0001A6A0();
void func_0005DA50();
void func_0003EB20();
void func_00042658();
extern s32 D_000CD960[];
extern char D_000B6950[];
extern char D_000B6970[];
extern s32 D_000BF50C;
extern char D_000B68F4[];

#endif
