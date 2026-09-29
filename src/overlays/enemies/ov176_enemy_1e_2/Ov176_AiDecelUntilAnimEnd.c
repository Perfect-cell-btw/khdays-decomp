/* Keeps the previous position and damps the velocity by 0xb00; once the animation ends queues
 * action 11 or 5 and ends the step. */

#include "game/actor.h"
#include "game/ai_task.h"

extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

struct E {
    char pad0[0xad];
    unsigned char fad;
};

struct V {
    int a;
    int b;
    int c;
};

struct B {
    Actor *p0;
    struct E *f4;
    char pad8[0x18];
    struct V at20;
    struct V at2c;
    char pad38[0x20];
    int f58;
    char pad5c[0x2c];
    int f88;
};

struct A {
    AI_TASK_FIELDS(struct B)
};

void Ov176_AiDecelUntilAnimEnd(struct A *a)
{
    struct B *b = a->pState;

    b->at20 = b->at2c;

    ScaleVec3Fx12(0xb00, &b->at2c, &b->at2c);

    if (b->f88 == 0 && b->at20.b < 0x20) {
        b->p0->flags60.bits.hi = b->p0->flags60.bits.hi & ~0x40;
    }

    if (b->f88 == 0 && !b->p0->contact17a.bits.bit0) {
        if (!b->p0->contact17c.bits.bit0) {
            return;
        }
    }

    if (b->f4->fad != 0) {
        return;
    }

    if (b->f58 > 0) {
        b->p0->nextState = 11;
        SetIndexedSlot(a, a->slot, 0);
    } else {
        b->p0->nextState = 5;
        SetIndexedSlot(a, a->slot, 0);
    }
}
