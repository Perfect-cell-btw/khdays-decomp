/* Advances the timer; at 0xd48 releases the hold flags, clears pendingAction and ends the step. */

#include "game/ai_task.h"

extern int SetIndexedSlot();

struct H {
    char pad0[0x60];
    unsigned short lo : 8;
    unsigned short hi : 8;
};

struct B {
    struct H *h;
    char pad4[0x48];
    int counter;
};

struct T {
    char pad0[0x2c];
    int inc;
};

struct A {
    AI_TASK_FIELDS(struct B)
};

void Ov228_AiHoldTick(struct A *a) {
    struct B *b = a->pState;
    b->counter += ((struct T *)a->pList)->inc;
    if (b->counter < 0xd48)
        return;
    b->h->hi &= ~1;
    {
        unsigned short *p = (unsigned short *)((char *)b->h + 0x60);
        unsigned short v = *p;
        unsigned int x = ((((unsigned int)v << 16) >> 24) | 0x80);
        *p = (unsigned short)((v & ~0xff00) | ((x << 24) >> 16));
    }
    *(unsigned char *)((char *)b->h + 0x1c7) = 0;
    SetIndexedSlot(a, a->slot, 0);
}
