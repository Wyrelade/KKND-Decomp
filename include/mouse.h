#ifndef MOUSE_H
#define MOUSE_H

#include "common.h"

/* Watcom union REGS, 16-bit view (int386x for the int 33h mouse driver) */
typedef struct MouseRegs {
    u16 ax; u16 _ax;
    u16 bx; u16 _bx;
    u16 cx; u16 _cx;
    u16 dx; u16 _dx;
    u16 si; u16 _si;
    u16 di; u16 _di;
    s32 cflag;
} MouseRegs;

typedef struct MouseSregs {
    u16 es;
    u16 cs;
    u16 ss;
    u16 ds;
    u16 fs;
    u16 gs;
} MouseSregs;

#endif
