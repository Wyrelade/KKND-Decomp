#ifndef VESA_H
#define VESA_H

#include "common.h"

/*
 * Fatal error (printf-style). Compiled as Watcom 10 __cdecl: callers save EBX/ECX/EDX
 * around the call. Open Watcom's __cdecl only clobbers EAX/ECX/EDX, so spell the
 * Watcom 10 register set out with a pragma.
 */
void func_00068320(char *fmt, ...);
#pragma aux func_00068320 modify [eax ebx ecx edx];

/* VBE library routine (not watcall; clobbers EBX/ECX/EDX). */
void func_00083093(void);
#pragma aux func_00083093 modify [eax ebx ecx edx];

/* One palette entry as the VBE palette call wants it (B, G, R, pad). */
typedef struct VesaRgbx {
    u8 c[4];
} VesaRgbx;

#endif
