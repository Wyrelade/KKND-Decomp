/* nearmiss func_000691D0 4 rp */
#include "common.h"
#include "ini.h"
/* DECLS */
extern u8 D_000B96B8[];
extern char D_000D57B5[];
extern char D_000C4D0C[];
void func_00014E42(void *a, void *b, int c, char *file, int line);
/* FUNC */
void func_000691D0(char *s)
{
    char *p = s;
    char c;
    if (*p != 0) {
        do {
            if (D_000B96B8[(u8)(*p + 1)] & 2)
                break;
            c = p[1];
            p++;
        } while (c != 0);
    }
    func_00014E42(D_000D57B5, p, 0x401, D_000C4D0C, 0x26f);
    func_00014E42(s, D_000D57B5, 4, D_000C4D0C, 0x270);
}
