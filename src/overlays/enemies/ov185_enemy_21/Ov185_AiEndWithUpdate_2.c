/* Sets the stance flags (hi byte bit 0 clear, |0x86), +0x1ae |= 3, clears child +0x388 bit 0, posts
 * update 0x120/4, clears pendingAction and ends the AI task. */

#include "game/actor.h"

extern int Ov107_BuildAndSendUpdate();
extern int SetIndexedSlot();

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct B {
    Actor *p0;
    char pad4[0x44 - 4];
    int f44;
};

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov185_AiEndWithUpdate_2(struct A *a)
{
    struct B *b = a->b;
    struct D *d;
    unsigned short v86 = 0x86;

    b->p0->flags60.bits.hi = b->p0->flags60.bits.hi & ~1;

    b->p0->flags60.bits.hi |= v86;

    b->p0->flags1ae = b->p0->flags1ae | 3;

    d = b->p0->pPoolEntry;
    d->f8 = d->f8 & ~1;

    Ov107_BuildAndSendUpdate(b->p0, 0x120, 4, b->f44);

    ((unsigned char *)b->p0)[0x1c7] = 0;

    SetIndexedSlot(a, a->f20, 0);
}
