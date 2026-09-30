/* Sets the stance flags (hi byte bit 0 clear, |6 |0x80), +0x1ae |= 3, clears child +0x388 bit 0,
 * posts an update, clears pendingAction and ends the AI task. */

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
    char pad4[4];
    int f8;
};

struct A {
    AI_TASK_FIELDS(struct B)
};

void Ov179_AiEndWithUpdate(struct A *a)
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

    Ov107_BuildAndSendUpdate(b->p0, 0, 0x4a, b->f8);

    ((unsigned char *)b->p0)[0x1c7] = 0;

    SetIndexedSlot(a, a->slot, 0);
}
