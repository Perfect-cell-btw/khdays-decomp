/* AI step: once the gate byte is clear, picks a random delay between the actor's limits at +0x224
 * and +0x228, queues action 2 and clears the step handler. */

#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);

void Ov156_stRandDelayInRange(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)state[1] == 0) {
        int lo = *(int *)(*state + 0x224);
        int hi = *(int *)(*state + 0x228);
        int d = hi - lo;
        if (d < 0) d = -d;
        state[0xd] = lo + RandNextScaled(d + 1);
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)(node + 8), (void *)0);
    }
}
