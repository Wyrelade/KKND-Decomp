#ifndef SERIAL_H
#define SERIAL_H

#include "common.h"

/* the retail strlen intrinsic encodes sub/xor as 29 c9 / 31 c0 (Open Watcom: 2b c9 / 33 c0) */
unsigned ser_strlen(char *s);
#pragma aux ser_strlen = 0x29 0xc9 0x49 0x31 0xc0 0xf2 0xae 0xf7 0xd1 0x49 parm [edi] value [ecx] modify exact [eax ecx edi];

/* inline port I/O as Watcom 10 emitted it (sub eax,eax = 29 c0 before in al,dx) */
void ser_outpb(unsigned port, u8 v);
#pragma aux ser_outpb = 0xee parm [edx] [al] modify exact [];
void ser_cli(void);
#pragma aux ser_cli = 0xfa modify exact [];
void ser_sti(void);
#pragma aux ser_sti = 0xfb 0xfc modify exact [];
unsigned ser_inp(unsigned port);
#pragma aux ser_inp = 0x29 0xc0 0xec parm [edx] value [eax] modify exact [eax];

typedef struct SerEvent {
    u8 _pad0[0x1D];
    void (*field_1D)(struct SerEvent *);
    u8 _pad21[0xA];
    s32 field_2B;
} SerEvent;

#endif
