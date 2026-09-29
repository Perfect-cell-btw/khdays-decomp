/* AI step: enters defeat: sets the defeat bits in the high byte of the actor's flags (+0x60) and
 * bit 0 of +0x1ae, clears bit 0 of its model's flag byte and clears the step handler. */

#include "nitro/types.h"
#include "game/actor.h"
#include "game/ai_task.h"

extern int SetIndexedSlot();

union F {
    u16 w;
    struct {
        u16 lo : 8;
        u16 hi : 8;
    } bf;
};

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct B {
    Actor *p0;
};

struct A {
    AI_TASK_FIELDS(struct B)
};

void Ov187_AiEnterDefeat(struct A *a)
{
    struct B *b = a->pState;
    struct D *d;

    b->p0->flags60.raw = (u16)((b->p0->flags60.raw & ~0xff00) | (((b->p0->flags60.bits.hi | 0xce) & 0xff) << 8));

    b->p0->flags1ae = b->p0->flags1ae | 1;

    d = b->p0->pPoolEntry;
    d->f8 = d->f8 & ~1;

    SetIndexedSlot(a, a->slot, 0);
}
