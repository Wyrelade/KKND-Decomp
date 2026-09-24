#ifndef MACHSHOP_H
#define MACHSHOP_H

#include "common.h"

typedef struct MachPlayer {
    u8 field_0;
    u8 _pad1[0xE];
    s32 field_F;
    s32 field_13;
    u8 _pad17[0x4];
} MachPlayer; /* size 0x1B */
typedef struct MachData { u8 _pad0[0xC]; s16 field_C; } MachData;
typedef struct MachUnit {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x4];
    s32 field_14;
    u8 _pad18[0x8];
    MachData *field_20;
} MachUnit;

void NETZ_Send();
void func_0001EF90();
void func_0001EF70();
void func_0004B600();
void func_0004C163();

extern MachPlayer D_000CC510[];
extern s32 D_000BDB8C;
extern s32 D_000BB88C;
extern s32 D_000BB890;
extern s32 D_000BDA34;
extern s32 D_000BF620;
extern s32 D_000BF5EC[];
extern char D_000BF5E0[];

#endif
