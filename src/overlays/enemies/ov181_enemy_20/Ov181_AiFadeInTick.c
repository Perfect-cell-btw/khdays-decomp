/* AI step: fades the actor in (the alpha at +0x394 grows with the timer up to 1.0); once the gate
 * byte clears, sets full alpha, picks a random range between the limits at +0x224/+0x228, queues
 * action 2 and clears the step handler. */

#include "game/actor.h"

extern int FX_Div();
extern int RandNextScaled();
extern int SetIndexedSlot();

typedef struct {
    char _pad0[0x2c];
    int field_2c;       /* +0x2c */
} Foo224;

typedef struct {
    Actor base;                  /* 0x000 */
    u8 pad38c[0x8];
    int field_394;      /* +0x394 */
} Inner;

typedef struct {
    Inner *p0;          /* +0x00 */
    char _pad4[0xc - 4];
    unsigned char *p_c; /* +0x0c */
    char _pad10[0x1c - 0xc - 4];
    int field_1c;       /* +0x1c */
    char _pad20[0x74 - 0x1c - 4];
    int field_74;       /* +0x74 */
} Mid;

typedef struct {
    Foo224 *p0;         /* +0x00 */
    Mid *p4;            /* +0x04 */
    char _pad8[0x20 - 8];
    signed char field_20;  /* +0x20 */
} Outer;

void Ov181_AiFadeInTick(Outer *o)
{
    Mid *m;
    int t;

    m = o->p4;
    t = m->field_1c + o->p0->field_2c;
    m->field_1c = t;

    t = FX_Div(t, 0x2aa);
    m->p0->field_394 = t;
    if (m->p0->field_394 > 0x1000)
        m->p0->field_394 = 0x1000;

    if (*m->p_c != 0)
        return;

    m->p0->field_394 = 0x1000;
    {
        int base = m->p0->base.field_224;
        int d = m->p0->base.field_228 - base;
        if (d < 0) d = -d;
        m->field_74 = base + RandNextScaled(d + 1);
    }
    m->p0->base.nextState = 2;
    SetIndexedSlot(o, o->field_20, 0);
}
