#ifndef CLANHALL_H
#define CLANHALL_H

#include "common.h"

typedef struct ClanLink { struct ClanLink *next; u8 _pad4[0x8]; s32 field_C; } ClanLink;
typedef struct ClanMgr { u8 _pad0[0x14]; ClanLink field_14; } ClanMgr;
typedef struct ClanFlagB { u8 _pad0[0xB]; u8 field_B; } ClanFlagB;
typedef struct ClanLnk2 { u8 _pad0[0x68]; ClanFlagB *field_68; } ClanLnk2;
typedef struct ClanLnk { u8 _pad0[0x4]; ClanLnk2 *field_4; } ClanLnk;
typedef struct ClanHdr { u8 _pad0[0xC]; s32 field_C; u8 _pad10[0x24]; void (*field_34)(); } ClanHdr;
typedef struct ClanPos { u8 _pad0[0x70]; s32 field_70; } ClanPos;
typedef struct ClanOwner { u8 _pad0[0x80]; s32 field_80; } ClanOwner;
typedef struct ClanUnit {
    u8 _pad0[0xC];
    ClanHdr *field_C;
    u8 _pad10[0x4];
    s32 field_14;
    u8 _pad18[0x4];
    ClanLnk *field_1C;
    u8 _pad20[0x18];
    ClanOwner *field_38;
    struct ClanUnit *field_3C;
    void (*field_40)();
    u8 _pad44[0x4];
    s32 field_48;
    u8 _pad4C[0x10];
    ClanPos *field_5C;
    u8 _pad60[0x34];
    s32 field_94;
} ClanUnit;

void func_0002A8E0();
void func_00039EF0();
int func_0002A3C0();
void func_0001BD80();
void func_0004EB90();
void func_0004E990();
ClanUnit *func_0001E310();
void func_0003A5A0();
void func_0004F710();
void func_0004F3A0();
void func_0004F4C0();
void func_0003A060();
void func_0003A170();
void func_00039E60();
void func_0005DC00();

typedef struct ClanReq { s32 field_0; s32 field_4; s32 field_8; } ClanReq;
typedef struct ClanLvl { s32 field_0; s32 field_4; } ClanLvl;
typedef struct ClanBData { u8 _pad0[0x10]; s32 field_10; } ClanBData;
typedef struct ClanBPos { u8 _pad0[0x70]; s32 field_70; } ClanBPos;
typedef struct ClanBld {
    u8 _pad0[0x14];
    s32 field_14;
    u8 _pad18[0x8];
    ClanBData *field_20;
    u8 _pad24[0x1C];
    void (*field_40)();
    u8 _pad44[0x4];
    void (*field_48)();
    u8 _pad4C[0x10];
    ClanBPos *field_5C;
} ClanBld;
extern ClanLvl D_000C3108[];
s32 func_0002AC90();
void func_0002AB60();
void func_0001DFB0();
extern ClanReq D_000BEB5C[];
extern s32 D_000BEAFC;
extern char D_000C300C[];
extern ClanMgr *D_000D0004;
extern s32 D_000BF620;
extern s32 D_000BE3C4;

#endif
