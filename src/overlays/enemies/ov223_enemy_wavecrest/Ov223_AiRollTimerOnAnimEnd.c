/* When the animation ends: rolls a random timer in [+0x224, +0x228], sets +0x78 and queues action
 * 6. */

#include "nitro/types.h"
#include "game/ai_task.h"
#include "game/engine.h"

extern int SetIndexedSlot();

struct S2 {
    u8 pad0[0x60];
    u16 lo8 : 8;    /* 0x60 low byte */
    u16 hi8 : 8;    /* 0x60 high byte */
};

struct S0 {
    struct S2 *p0;  /* 0x00 */
    u8 *p4;         /* 0x04 */
    u8 pad8[0x68 - 8];
    int f68;        /* 0x68 */
    u8 pad6c[0x78 - 0x6c];
    int f78;        /* 0x78 */
};

struct This {
    AI_TASK_FIELDS(struct S0)
};

void Ov223_AiRollTimerOnAnimEnd(struct This *this)
{
    struct S0 *s0 = this->pState;
    struct S2 *s2 = s0->p0;
    int diff;

    s2->hi8 = s2->hi8 & ~0xE;

    if (s0->p4[0xad] != 0)
        return;

    {
        int a = *(int *)((u8 *)s0->p0 + 0x224);
        int b = *(int *)((u8 *)s0->p0 + 0x228);
        diff = b - a;
        if (diff < 0) diff = -diff;
        s0->f68 = a + RandNextScaled(diff + 1);
    }
    s0->f78 = 1;
    *((u8 *)s0->p0 + 0x1c7) = 6;
    SetIndexedSlot(this, (s8)this->slot, 0);
}
