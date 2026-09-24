#ifndef COMMON_H
#define COMMON_H

/*
 * Shared definitions for the KKND decompilation.
 *
 * Target: KKND.EXE (Krush Kill 'n Destroy, Beam Software 1997), Watcom C 32-bit,
 * register calling convention (`-3r`/`-5r` style: args in EAX, EDX, EBX, ECX), DOS/4GW.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;

/*
 * INCLUDE_ASM(dir, name): a function not yet decompiled. tools/build_kknd.py keeps the
 * original bytes for it; the listing lives in asm/DOS/nonmatchings/<name>.s.
 * It expands to a harmless unique extern so a `;` after it is a valid declaration.
 */
#define INCLUDE_ASM(dir, name) extern int INCLUDE_ASM_##name

#endif
