/* Recover tick of the ov238 actor: once its guard flag (+0x60 bit 0) is up, the +0x28 rest is rolled
 * between +0x224 and +0x228, pose 0x16 loops and the queued +0x1c9 move becomes next. */

#include "nitro/types.h"

typedef struct { u16 lo : 8; u16 hi : 8; } flags16;

extern int RandNextScaled(int bound);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov238_RecoverTick(int *node)
{
    int *state = (int *)node[1];
    int lo;
    int span;

    if ((((flags16 *)(*state + 0x60))->lo & 1) == 0) {
        return;
    }
    lo = *(int *)(*state + 0x224);
    span = *(int *)(*state + 0x228) - lo;
    if (span < 0) {
        span = -span;
    }
    state[0xa] = lo + RandNextScaled(span + 1);
    Ov107_PostTagUpdate(*state, 0x16, 1);
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
