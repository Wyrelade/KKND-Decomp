/* nearmiss func_00019D80 18 sched */
#include "common.h"
#include "mouseptr.h"
/* TYPES */
/* 13-byte pointer event record queued by func_00019D80. */
typedef struct MpEvent {
    u8 data[13];
} MpEvent;

typedef struct MpEvNode {
    struct MpEvNode *next;
    MpEvent ev;
} MpEvNode;
/* DECLS */
extern MpEvNode *D_000CC678;
extern MpEvNode *D_000CC67C;
/* FUNC */
void func_00019D80(MpEvent *e)
{
    MpEvNode *n = D_000CC678;
    MpEvNode *p = D_000CC67C;
    if (n != 0) {
        n->ev = *e;
        D_000CC678 = n->next;
        n->next = 0;
        if (p != 0) {
            while (p->next != 0)
                p = p->next;
            p->next = n;
        } else {
            D_000CC67C = n;
        }
    }
}
