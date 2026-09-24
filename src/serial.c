/* serial.c: 53 functions (unit boundaries [H], see configs/DOS/units.csv) */
#include "common.h"
#include "serial.h"
/* decls */
extern void (*D_000BDBB4)(int, char *, ...);
extern void (*D_000BDBB0)(SerEvent *);
extern char D_000B7684[], D_000B76AC[], D_000D3FE4[];
extern int D_000C42C4;
SerEvent *NETZ_AddEvent(int, int, int, int, int, int);
int NETZ_OpenLink(char *, int);
int NETZ_CancelEvent(SerEvent *);
extern u8 D_000D1EE1;
extern s32 D_000D1EF6;
extern char D_000C42F1[];
void SER_Init(void);
extern char D_000C42EC[];
extern char D_000B76D4[];
void func_0004C163(void *, int, int, char *, int, int);
void func_00014D18(int line, char *file);
#pragma aux func_00014D18 parm routine [];
void func_00014D9B(char *, char *, ...);
int func_0005E450(char *);
extern char D_000D3FD9[];
void func_00014E42(char *, char *, int, char *, int);
extern char D_000B7568[], D_000C427C[], D_000B1B70[], D_000B1B3C[];
extern u16 D_000C4292;
extern u8 D_000D1EE0;
extern int D_000C42BC, D_000C42B8, D_000D4250;
extern char D_000D4254[];
void do_send(int, int, int, int, int);
void func_0005F410(); void func_0005F030(); void NETZ_ReleasePacket(void *);
void func_0004C09C(int, char *, int); void func_0005E340(void); void func_0005F360(char *, int);

int func_0005E360(char *s)
{
    if (ser_strlen(s) > 10 || ser_strlen(s) == 0)
        return 1;
    func_00014E42(D_000D3FD9, s, 11, D_000C427C, 0xB9B);
    return 0;
}
int func_0005E3C0(char *s)
{
    char buf[20];
    if (ser_strlen(s) == 0)
        return 1;
    func_0004C163(buf, 0, 20, D_000C427C, 0xB8E, 20);
    func_00014D18(0xB8F, D_000C427C);
    func_00014D9B(buf, D_000B76D4, D_000C42EC, s);
    return func_0005E450(buf);
}
int func_0005E440(void)
{
    return 0;
}

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E450);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E4E0);
int func_0005E560(void)
{
    if (D_000D1EE0 && !D_000D1EE1)
        SER_Init();
    if (D_000D1EE0) {
        ser_cli();
        ser_outpb(D_000D1EF6, ser_inp(D_000D1EF6) & 0xFE);
        ser_sti();
    }
    if (D_000D1EE0) {
        ser_cli();
        ser_outpb(D_000D1EF6, ser_inp(D_000D1EF6) | 1);
        ser_sti();
    }
    func_0005E450(D_000C42F1);
    return 0;
}
int func_0005E5D0(void) { return D_000D1EE0 == 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E5F0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E6D0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E700);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E770);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E7E0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005E8F0);
int func_0005E9C0(void)
{
    SerEvent *e = NETZ_AddEvent(3, 1, 0, 0, 0, 0);
    SerEvent *ev = e;
    int h;
    void (*fn)(SerEvent *);
    if (!e) {
        D_000BDBB4(0x45, D_000B7684);
        return -1;
    }
    h = NETZ_OpenLink(D_000D3FE4, 0);
    if (h == -1) {
        D_000BDBB4(0x45, D_000B76AC);
    } else {
        D_000C42C4 = h;
        fn = e->field_1D;
        e->field_2B = h;
        if (fn)
            ev->field_1D(e);
        else
            D_000BDBB0(e);
        NETZ_CancelEvent(ev);
    }
    return h;
}
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EA60);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EAD0);
void func_0005EB70(int a) { if (a) func_0004C09C(a, D_000C427C, 0x972); }

INCLUDE_ASM("asm/DOS/nonmatchings", SER_GrabSenderAddress);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EC30);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005ECA0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005EE80);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F030);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F0AC);
char *func_0005F2A0(void) { return D_000B7568; }

void func_0005F2B0(void)
{
}

INCLUDE_ASM("asm/DOS/nonmatchings", SER_LostLink);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F410);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F4B0);
void func_0005F4E0(void) { func_0005F410(); func_0005F030(); }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F500);
INCLUDE_ASM("asm/DOS/nonmatchings", do_send);
void func_0005F7F0(int a, u8 b, int c, int d) { do_send(a, b, c, d, 1); }

void func_0005F810(void) { func_0005F360(D_000D4254, D_000D4250); func_0005F030(); }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F830);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F880);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F8A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005F930);
INCLUDE_ASM("asm/DOS/nonmatchings", SER_Init);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FA50);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FA90);
int func_0005FB30(u16 x) { D_000C4292 = x; return 0; }

INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FB40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FC00);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FC70);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FE40);
INCLUDE_ASM("asm/DOS/nonmatchings", func_0005FFD0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000600B0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000601A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00060280);
INCLUDE_ASM("asm/DOS/nonmatchings", func_00060360);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000603A0);
INCLUDE_ASM("asm/DOS/nonmatchings", func_000603E0);
