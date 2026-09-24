/* nearmiss func_00068960 34 ci */
#include "common.h"
#include "vesa.h"
/* DECLS */
extern s32 D_000D5240;
extern s32 D_000D5224;
extern void *D_000C4780;
extern char D_000C4754[];
void func_0004C09C(void *p, char *file, int line);
#pragma aux func_0004C09C modify exact [eax ebx edx];
void func_000825E9(void);
void func_00081062(void);
void func_00080F0C(void);
#pragma aux func_00080F0C modify exact [eax ebx ecx edx];
/* FUNC */
void func_00068960(void)
{
    if (D_000D5240 != 0) {
        if (D_000C4780 != 0) {
            func_0004C09C(D_000C4780, D_000C4754, 0x21f);
            D_000C4780 = 0;
        }
        func_000825E9();
        func_00081062();
        func_00080F0C();
        D_000D5240 = 0;
        D_000D5224 = 0;
    }
}
