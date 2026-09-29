/* AI step: once track-0 animation ends, context +0x34 = a random value in the actor's Ms/UP range
 * (+0x224..+0x228), pendingAction = 2, step cleared. */

#include "game/engine.h"

extern int SetIndexedSlot();

struct sub {
    int *f0;
    int *f4;
    char gap8[0x2c];
    int f34;
};

struct top {
    char gap0[4];
    struct sub *f4;
    char gap8[0x18];
    signed char b20;
};

void Ov196_AiStep_RollDelayQueueAction2OnAnimEnd_2(struct top *a) {
    struct sub *s = a->f4;
    int *p;
    int lo, hi, diff;

    if (*(unsigned char *)((char *)s->f4 + 0xad) != 0)
        return;

    p = s->f0;
    lo = p[0x224 / 4];
    hi = p[0x228 / 4];
    diff = hi - lo;
    if (diff < 0)
        diff = -diff;
    diff = diff + 1;
    s->f34 = lo + RandNextScaled(diff);

    *(unsigned char *)((char *)s->f0 + 0x1c7) = 2;

    SetIndexedSlot(a, a->b20, 0);
}
