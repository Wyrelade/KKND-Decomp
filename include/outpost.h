#ifndef OUTPOST_H
#define OUTPOST_H

#include "common.h"

typedef struct OutRes { u8 _pad0[0x28]; s32 field_28; } OutRes;
typedef struct OutNode { struct OutNode *next; OutRes *field_4; } OutNode;
typedef struct OutList { u8 _pad0[0x8]; OutNode *field_8; s32 field_C; } OutList;
typedef struct OutSub { u8 _pad0[0x7C]; s32 *field_7C; } OutSub;
typedef struct OutObj {
    u8 _pad0[0x18];
    OutSub *field_18;
    s32 field_1C;
} OutObj;

typedef struct OutPos { u8 _pad0[0x1C]; s32 field_1C; s32 field_20; u8 _pad24[0x4C]; s32 field_70; } OutPos;
typedef struct OutCtl { u8 _pad0[0x90]; s32 field_90; } OutCtl;
typedef struct OutData {
    u8 _pad0[0x4];
    s32 field_4;
    s32 field_8;
    s16 field_C;
    u8 _padE[0x2];
    s32 field_10;
} OutData;
typedef struct OutState {
    void (*field_0)();
    s32 field_4;
    u8 _pad8[0x4];
    s32 field_C;
    OutCtl *field_10;
    s32 field_14;
    u8 _pad18[0x8];
    OutData *field_20;
} OutState;
typedef struct OutHdr { u8 _pad0[0xC]; s32 field_C; u8 _pad10[0x24]; void (*field_34)(); } OutHdr;
typedef struct OutFlagB { u8 _pad0[0xB]; u8 field_B; } OutFlagB;
typedef struct OutLnk2 { u8 _pad0[0x68]; OutFlagB *field_68; } OutLnk2;
typedef struct OutLnk { u8 _pad0[0x4]; OutLnk2 *field_4; } OutLnk;
typedef struct OutWp { s32 x; s32 y; s32 i; } OutWp;
typedef struct OutPt { s32 x; s32 y; } OutPt;
typedef struct OutPos2 { u8 _pad0[0x70]; s32 field_70; } OutPos2;
typedef struct OutUnit {
    u8 _pad0[0xC];
    OutHdr *field_C;
    u8 _pad10[0x4];
    s32 field_14;
    u8 _pad18[0x4];
    OutLnk *field_1C;
    OutData *field_20;
    u8 _pad24[0x18];
    struct OutUnit *field_3C;
    void (*field_40)();
    u8 _pad44[0x4];
    void (*field_48)();
    u8 _pad4C[0x10];
    OutPos *field_5C;
    u8 _pad60[0x48];
    s32 field_A8;
    s32 field_AC;
    s32 field_B0;
    u8 _padB4[0x84];
    s32 field_138;
} OutUnit;

void func_0003B660();
void func_0003B510();
void func_0003AE80();
void func_000514C0();
int func_0002A8E0();
extern s32 D_000BF620;
typedef struct OutOwner { u8 _pad0[0x8]; OutCtl *field_8; } OutOwner;
typedef struct OutTask {
    void (*field_0)();
    s32 field_4;
    s32 field_8;
    s32 field_C;
    OutCtl *field_10;
    u8 _pad14[0x4];
    OutOwner *field_18;
    struct OutBld *field_1C;
} OutTask;
typedef struct OutBld {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x24];
    void (*field_34)();
    OutOwner *field_38;
    OutTask *field_3C;
} OutBld;
OutTask *func_0001A010();
void func_0003B4D0();
void func_0003B6A0();
void func_0003BB30();
void func_0001BD80();
void func_0001DFB0();
typedef struct OutLvl { s32 field_0; s32 field_4; } OutLvl;
extern OutLvl D_000C3108[];
s32 func_0002AC90();
extern s32 D_000BF4EC;
void func_0002AB60();
void func_0005D580();
int func_0002A3C0();
void func_0003B1B0();
int func_0004C163();
typedef struct OutReq { s32 field_0; s32 field_4; s32 field_8; } OutReq;
extern OutReq D_000BEB20[];
void func_0004C0F7();
#pragma aux func_0004C0F7 parm [eax] [edx] [ecx]
extern char D_000C300C[];
extern char D_000BEAE4[];
extern s32 D_000BEAF8[];
extern s32 D_000BEA50[];
extern s32 D_000CFFF0[];
extern s32 D_000BEAF4;
extern s32 D_000D0004;
extern s32 D_000D0000;
extern s32 D_000BEAF0;
extern s32 D_000BEA74;
void func_0004EB90();
void func_0004E990();
extern s32 D_000BE3C4;
extern s32 D_000BB290;
extern OutPt D_000BF3D4[];
extern OutPt D_000BF464[];
OutUnit *func_0001E310();
void func_0004F3A0();
void func_0004F4C0();
void func_0004F710();
void func_0003B790();
void func_0003B750();
void func_0003B8B0();
void func_0003B6D0();
void func_0003BBB0();
void func_0003BD84();
void func_0003BA80();
void func_0003BCF0();
void func_0004EED0();
void func_0003B080();
void func_0004E7D0();
void func_0002D530();
void func_0001AA80();
void func_00019F90();

extern s32 D_000BEB1C;

#endif
