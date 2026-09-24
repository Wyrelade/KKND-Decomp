#ifndef KEY2_H
#define KEY2_H

#include "common.h"

/* IPX-style node address as stored behind D_000D7080. */
typedef struct NetAddr {
    u8 _pad0[0x4];
    u8 field_4[6];
} NetAddr;

/*
 * Watcom 10.x inline memcmp. Open Watcom's own intrinsic is the same sequence except that
 * it encodes `xor eax,eax` as 33 c0 where Watcom 10 used 31 c0, so spell it out.
 */
int wc10_memcmp(const void *a, const void *b, unsigned n);
#pragma aux wc10_memcmp = \
    0x31 0xc0          /* xor eax,eax */ \
    0xf3 0xa6          /* repe cmpsb */ \
    0x74 0x05          /* je +5 */ \
    0x19 0xc0          /* sbb eax,eax */ \
    0x83 0xd8 0xff     /* sbb eax,-1 */ \
    parm [esi] [edi] [ecx] value [eax] modify exact [eax esi edi ecx];

/* Request dispatched by func_0006DE00 on field_18->field_4C (a mode/flag word). */
typedef struct Key2Info {
    u8 _pad0[0x4C];
    u32 field_4C;
} Key2Info;

typedef struct Key2Req {
    u8 _pad0[0x18];
    Key2Info *field_18;
} Key2Req;

#endif
