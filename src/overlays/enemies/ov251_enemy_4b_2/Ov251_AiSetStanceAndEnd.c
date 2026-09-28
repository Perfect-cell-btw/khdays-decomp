/* AI step: sets the stance bits in the high byte of the actor's flags (+0x60) and bit 0 of the
 * flags at +0x1ae, clears bit 0 of its model's flag byte, then clears the step handler. */

#include "game/actor.h"

extern int SetIndexedSlot();

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct B {
    Actor *p0;
};

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov251_AiSetStanceAndEnd(struct A *a)
{
    struct B *b = a->b;
    Actor *c;
    struct D *d;
    unsigned int x;

    c = b->p0;
    x = c->flags60.raw;
    c->flags60.raw = (x & ~0xff00) | (((((x << 16) >> 24) | 0x86) << 24) >> 16);

    c = b->p0;
    c->flags1ae = c->flags1ae | 1;

    d = b->p0->pPoolEntry;
    d->f8 = d->f8 & ~1;

    SetIndexedSlot(a, a->f20, 0);
}
