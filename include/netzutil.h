#ifndef NETZUTIL_H
#define NETZUTIL_H

#include "common.h"

typedef struct NetzEvent {
    s32 field_0;
    struct NetzEvent *field_4;
    u8 _pad8[4];
    u8 field_C;
    u8 _padD[0x1E];
    s32 field_2B;
} NetzEvent;

typedef struct NetzPacket {
    s32 field_0;
    struct NetzPacket *field_4;
    u8 field_8[4];
} NetzPacket;

typedef struct NetzPlayer {
    u8 _pad0[0xC];
    s32 field_C;
    u8 _pad10[0x3C];
    s32 field_4C;
} NetzPlayer;

typedef struct NetzGame {
    u8 _pad0[8];
    s32 field_8;
    u8 _padC[0x18];
    NetzPlayer *field_24;
} NetzGame;

typedef struct NzPeer {
    u8 _pad0[8];
    s32 field_8;
} NzPeer;

typedef struct NzPlayerFlags {
    u8 field_0;
    u8 _pad1[7];
} NzPlayerFlags;

/* Watcom REGS (32-bit view) / SREGS for int386x */
typedef struct NzRegs {
    s32 eax;
    s32 ebx;
    s32 ecx;
    s32 edx;
    s32 esi;
    s32 edi;
    s32 cflag;
} NzRegs;

typedef struct NzSregs {
    u16 es;
    u16 cs;
    u16 ss;
    u16 ds;
    u16 fs;
    u16 gs;
} NzSregs;

#endif
