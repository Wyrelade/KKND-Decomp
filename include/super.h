#ifndef SUPER_H
#define SUPER_H

#include "common.h"

typedef struct SuperObjC { u8 _pad0[0xC]; u8 field_C; } SuperObjC;
typedef struct SuperObj24 { u8 _pad0[0x24]; s32 field_24; } SuperObj24;
typedef struct SuperNode { struct SuperNode *next; SuperObj24 *field_4; } SuperNode;
typedef struct SuperList { u8 _pad0[0x8]; SuperNode *field_8; s32 field_C; } SuperList;
typedef struct SuperSub {
    u8 _pad0[0x8];
    struct SuperSub *field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    u8 _pad20[0x60];
    SuperObjC *field_80;
} SuperSub;
typedef struct SuperEnt {
    u8 _pad0[0x10];
    s32 field_10;
    s32 field_14;
    u8 _pad18[0x54];
    s32 field_6C;
    u8 _pad70[0x18];
    s32 field_88;
} SuperEnt;
typedef struct SuperLink { struct SuperLink *next; u8 _pad4[0x8]; s32 field_C; } SuperLink;
typedef struct SuperMgr { u8 _pad0[0x14]; SuperLink field_14; } SuperMgr;
typedef struct SuperGfx { u8 _pad0[0x34]; s32 field_34; s32 field_38; s32 field_3C; } SuperGfx;
typedef struct SuperObj {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x8];
    SuperGfx *field_18;
    u8 _pad1C[0x1C];
    SuperSub *field_38;
    u8 _pad3C[0x4];
    void (*field_40)();
    u8 _pad44[0x18];
    SuperEnt *field_5C;
    u8 _pad60[0x20];
    s32 field_80;
    u8 _pad84[0xAC];
    s32 field_130;
} SuperObj;

SuperObjC *func_00033340();
void func_0001A270();
void func_000380D0();
void func_000281D0();
void func_00028220();
void func_00019F90();
void func_00039410();
void func_0004E7D0();
void func_0001E270();
int func_000334C0();
int func_000336B0();
void func_00049D50();
void *func_00027440();
void func_00026F40();
void func_0001A060();
void func_00039070();
void func_00039120();
void func_0001A6E0();
void func_00033C30();
int func_00038210();
void mubuttons();
void func_0002A8E0();
void func_0001A6A0();
void func_00038DA0();
void func_00038740();
void func_00038B00();
void func_00039240();
SuperSub *func_0001AB70();
void func_00052390();
void func_00032680();
s32 func_00032650();
void func_00033AD0();
void func_0004B670();
void func_0001BD80();
void func_00051530();
void func_0001AA80();
void func_0001E1F0();
void func_0004E920();
void func_0004D47C();
void func_0001C9F0(char *, ...);

extern s32 D_000CFFC8;
extern s32 D_000BE7E0;
extern s32 D_000BE8EC;
extern s32 D_000BE8F0;
extern s32 D_000BE7CC;
extern s32 D_000BB898;
extern u8 D_000CFFE2;
extern u8 D_000CFFE0[];
extern u8 D_000B5200[];
extern u8 D_000B4E94[];
extern u8 D_000B4E8C[];
extern u8 D_000B4E88[];
extern SuperMgr *D_000D0004;
extern SuperMgr *D_000D0000;
extern SuperSub *D_000CFFD8;
extern SuperSub *D_000CFFCC;
extern SuperEnt *D_000CFFDC;
extern s32 D_000BE3C4;
extern s32 D_000BF620;
extern char D_000BE7BC[];
extern char D_000B50A8[];
extern u8 D_000CFFE1;
extern u8 D_000CFFE3;
extern u8 D_000B96B8[];
extern s32 D_000CD960[];

#endif
