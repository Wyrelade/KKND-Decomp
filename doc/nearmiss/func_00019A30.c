/* nearmiss func_00019A30 17 fold */
#include "common.h"
#include "mouseptr.h"
/* DECLS */
void func_0004B670();
extern s32 D_000CC680;
/* FUNC */
void func_00019A30(MpNode *head, s32 b, s32 c)
{
    MpNode *n;
    for (n = head->field_0; n != head; n = n->field_0)
        func_0004B670(D_000CC680, b, c, n->field_8);
}
