/* AI step: once the actor is active, picks a random wait between the actor's limits, clears the
 * counter, makes the stored action pending and clears the step handler. */

#include "game/engine.h"

struct hw60 { unsigned short lo : 8, hi : 8; };

extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov298_RerollTimerThenAdvance(int node) {
    int *state = *(int **)(node + 4);
    int obj = *state;
    int start;
    int delta;

    if ((((struct hw60 *)(obj + 0x60))->lo & 1) == 0) return;

    start = *(int *)(obj + 0x224);
    delta = *(int *)(obj + 0x228) - start;
    if (delta < 0) {
        delta = -delta;
    }

    state[0xf] = start + RandNextScaled(delta + 1);
    state[0x12] = 0;
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), 0);
}
