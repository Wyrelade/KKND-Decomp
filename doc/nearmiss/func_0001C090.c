/* nearmiss func_0001C090 58 isel */
#include "common.h"
#include "sound.h"
/* DECLS */
void func_0004C080(char *fmt, ...);
extern char D_000B1950[];
int func_0001BBF0();
/* FUNC */
int func_0001C090(SndList *s)
{
    SndSlot *p = s->f14;
    if (s->fC < (u32)s->f4) {
        p += s->fC;
        switch (p->f4) {
        case 0:
        case 1:
            return func_0001BBF0(p->f10);
        default:
            func_0004C080(D_000B1950, s->fC, p->f4);
        }
    }
    return 0;
}
