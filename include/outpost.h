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

void func_0003BB30();
void func_0004E7D0();
void func_0002D530();
void func_0001AA80();
void func_00019F90();

extern s32 D_000BEB1C;

#endif
