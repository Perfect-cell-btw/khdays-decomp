/* AI step: sets the stance bits (6 and 0x80) and contact flags, sends the action 0x4b update,
 * queues action 0 and ends the step. */

#include "game/actor.h"
#include "game/ai_task.h"

extern int Ov107_BuildAndSendUpdate();
extern int SetIndexedSlot();

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct B {
    Actor *p0;
    char pad4[8];
    int fc;
};

struct A {
    AI_TASK_FIELDS(struct B)
};

void Ov292_ExitChase(struct A *a)
{
    struct B *b = a->pState;
    struct D *d;
    unsigned short v6 = 6;
    unsigned short v80 = 0x80;

    b->p0->flags60.bits.hi = b->p0->flags60.bits.hi & ~1;

    b->p0->flags60.bits.hi |= v6;

    b->p0->flags1ae = b->p0->flags1ae | 3;

    d = b->p0->pPoolEntry;
    d->f8 = d->f8 & ~1;

    b->p0->flags60.bits.hi |= v80;

    Ov107_BuildAndSendUpdate(b->p0, 0, 0x4b, b->fc);

    ((unsigned char *)b->p0)[0x1c7] = 0;

    SetIndexedSlot(a, a->slot, 0);
}
