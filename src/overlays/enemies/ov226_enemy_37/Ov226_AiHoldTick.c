/* Advances the timer; at 3400 releases the hold flags, clears pendingAction and ends the step. */

#include "game/actor.h"

extern int SetIndexedSlot();

struct E {
    char pad0[0x2c];
    int f2c;
};

struct B {
    Actor *p0;
    char pad4[0x58];
    int f5c;
};

struct A {
    struct E *f0;
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov226_AiHoldTick(struct A *a)
{
    struct B *b = a->b;

    b->f5c += a->f0->f2c;
    if (b->f5c < 3400)
        return;

    b->p0->flags60.bits.hi |= (unsigned char)0x80;
    b->p0->flags60.bits.hi &= ~1;

    b->p0->nextState = 0;

    SetIndexedSlot(a, a->f20, 0);
}
