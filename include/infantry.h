#ifndef INFANTRY_H
#define INFANTRY_H

#include "common.h"

typedef struct InfE4 { u8 _pad0[0x134]; s32 field_134; } InfE4;
typedef struct InfOwner {
    u8 _pad0[0x10];
    s32 field_10;
    u8 _pad14[0x7C];
    s32 field_90;
    u8 _pad94[0x50];
    InfE4 *field_E4;
} InfOwner;
typedef struct InfState {
    u8 _pad0[0x8];
    InfOwner *field_8;
    s32 field_C;
    int (*field_10)();
    u8 _pad14[0x4];
    s32 field_18;
    u8 _pad1C[0x14];
    s32 field_30;
} InfState;
typedef struct InfAnim {
    u8 _pad0[0x8];
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
} InfAnim;
typedef struct InfFlags { u8 _pad0[0x27]; u8 field_27; } InfFlags;
typedef struct InfFx {
    InfFlags *field_0;
    s32 field_4;
    InfOwner *field_8;
    u8 _padC[0x4];
    int (*field_10)();
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    u8 _pad20[0x8];
    InfAnim *field_28;
} InfFx;
typedef struct InfPos { u8 _pad0[0x10]; s32 field_10; s32 field_14; u8 _pad18[0x4]; s32 field_1C; s32 field_20; } InfPos;
typedef struct InfGfx { u8 _pad0[0x38]; s32 field_38; s32 field_3C; } InfGfx;
typedef struct InfUnit {
    u8 _pad0[0xC];
    s32 field_C;
    s32 field_10;
    u8 _pad14[0x4];
    InfGfx *field_18;
    u8 _pad1C[0x20];
    InfState *field_3C;
    void (*field_40)();
    u8 _pad44[0x18];
    InfPos *field_5C;
    u8 _pad60[0x20];
    s32 field_80;
    u8 _pad84[0x8];
    s32 field_8C;
    s32 field_90;
    u8 _pad94[0x14];
    s32 field_A8;
    s32 field_AC;
    s32 field_B0;
    u8 _padB4[0x78];
    s32 field_12C;
    u8 _pad130[0x4];
    s32 field_134;
    u8 _pad138[0x11C];
    s32 field_254;
    s32 field_258;
} InfUnit;

void func_0003F160();
void func_00046920();
void func_0001C9E0(void *, char *, ...);
void func_00042658();
void func_0003E1E0();
void func_000514C0();
void func_0001AA80();
void func_00019F90();
void func_0001E270();
void func_0001A6A0();
void func_0001A060();
int func_0001DE10();
void func_00046540();
void func_000464F0();
int func_0005E091(int, ...);
int func_0006E760();
void func_000429B0();
void func_0003F710();
void func_00051480();
void func_00046800();
void func_000466A0();
void func_000464B0();
void func_000465A0();
void func_0005D2B0();
void func_0005D290();
void func_0006C360();
void func_0003D170();

extern char D_000B63AC[];
extern char D_000B5A58[];
extern char D_000B6470[];
extern char D_000B6448[];
extern s32 D_000BD8F0;
extern s32 D_000CD960[];

#endif
