/* AI step: once the actor is active, picks a random wait between the actor's limits, makes the
 * stored action (+0x1c9) pending and clears the step handler. */

#include "game/engine.h"

extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov204_RerollTimerIfHitFlag(int node)
{
    int *state = *(int **)(node + 4);
    int start;
    int range;
    int flags;

    flags = *(unsigned short *)(*state + 0x60);
    flags = (unsigned int)(flags << 24) >> 24;
    if ((flags & 1) == 0) {
        return;
    }

    start = *(int *)(*state + 0x224);
    range = *(int *)(*state + 0x228) - start;
    if (range < 0) {
        range = -range;
    }
    state[0x30 / 4] = start + RandNextScaled(range + 1);
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), 0);
}
