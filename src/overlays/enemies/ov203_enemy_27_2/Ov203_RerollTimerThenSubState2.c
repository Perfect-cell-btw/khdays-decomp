/* AI step: once the gate byte is clear, picks a random wait between the actor's limits at +0x224
 * and +0x228, queues action 2 and clears the step handler. */

#include "game/engine.h"

extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov203_RerollTimerThenSubState2(int node)
{
    int *state = *(int **)(node + 4);
    int obj;
    int start;
    int range;

    if (*(unsigned char *)state[0x44 / 4] != 0) {
        return;
    }

    obj = *state;
    start = *(int *)(obj + 0x224);
    range = *(int *)(obj + 0x228) - start;
    if (range < 0) {
        range = -range;
    }
    state[0x30 / 4] = start + RandNextScaled(range + 1);
    *(signed char *)(*state + 0x1c7) = 2;
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), 0);
}
