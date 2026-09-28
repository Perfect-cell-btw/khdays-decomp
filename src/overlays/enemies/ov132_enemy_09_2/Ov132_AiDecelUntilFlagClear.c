/* Keeps the previous position and damps the velocity by 0xb00 until the watched flag clears. */

#include "game/actor.h"

extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

struct V {
    int a;
    int b;
    int c;
};

struct B {
    Actor *p0;
    char pad4[0x14];
    struct V at20;
    struct V at2c;
    char pad30[0x18];
    unsigned char *f48;
};

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov132_AiDecelUntilFlagClear(struct A *a)
{
    struct B *b = a->b;
    Actor *c;

    b->at20 = b->at2c;

    ScaleVec3Fx12(0xb00, &b->at2c, &b->at2c);

    if (*b->f48 != 0) {
        return;
    }

    c = b->p0;
    if (!c->contact17a.bits.bit0) {
        if (!c->contact17c.bits.bit0) {
            return;
        }
    }

    c->nextState = 2;
    SetIndexedSlot(a, a->f20, 0);
}
