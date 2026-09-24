#ifndef NIPX_H
#define NIPX_H

#include "common.h"

/* DPMI real-mode call structure (INT 31h AX=0300h) */
typedef struct RmRegs {
    s32 edi;
    s32 esi;
    s32 ebp;
    s32 _res;
    s32 ebx;
    s32 edx;
    s32 ecx;
    s32 eax;
    u16 flags;
    u16 es;
} RmRegs;

typedef struct IpxEcb {
    s32 field_0;
    u16 field_4;
    u8 _pad6[8];
    u8 field_E;
    u8 _padF[0x147];
    struct IpxEcb *field_156;
} IpxEcb;

#endif
