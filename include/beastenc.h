#ifndef BEASTENC_H
#define BEASTENC_H

#include "common.h"

typedef struct BeastCnt { u8 _pad0[0x4]; s32 field_4; } BeastCnt;
typedef struct BeastState { u8 _pad0[0x20]; BeastCnt *field_20; } BeastState;
typedef struct BeastObj {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x2C];
    BeastState *field_3C;
    void (*field_40)();
    u8 _pad44[0x4C];
    s32 field_90;
    s32 field_94;
} BeastObj;

void func_0005D580();
void func_0003C500();
void func_0001A060();
void func_0004B600();
void func_0004E7D0();
void func_0001C9E0(void *, char *, ...);
void func_0003E000();
void func_00031870();

extern s32 D_000BF50C;
extern char D_000B68F4[];

#endif
