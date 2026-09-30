/* Queues action 2 when the animation ends. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct A {
    AI_TASK_FIELDS(struct B)
};

struct B {
    unsigned char *p0;
    struct C *c;
};

struct C {
    unsigned char f0[0xad];
    unsigned char fad;
};

void Ov189_AiStep_QueueAction2OnAnimEnd_2(struct A *a)
{
    struct B *b = a->pState;
    if (b->c->fad != 0)
        return;
    b->p0[0x1c7] = 2;
    SetIndexedSlot(a, a->slot, 0);
}
