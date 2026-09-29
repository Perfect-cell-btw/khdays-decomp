/* State step: binds the child actor (+0x3c4's subitem) to this state: installs its render callback
 * and back pointer, clears its flag bit 1, starts its animation tracks, resets the timer and
 * installs the timer step. */

#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov164_RenderAtOwnerScaled(void);
extern void Ov164_TickTimerAdvanceSubState(void);

void Ov164_stInitChildActor(int *node) {
    int *state = (int *)node[1];
    state[1] = *(int *)(*(int *)(*state + 0x3c4) + 0x18);
    *(void **)(state[1] + 0x6c) = Ov164_RenderAtOwnerScaled;
    *(int **)(state[1] + 0x84) = state;
    *(int *)(state[1] + 0x5c) &= ~2;
    state[3] = 6;
    SetSubitemState((void *)state[1], 0, 0, 1);
    SetSubitemState((void *)state[1], 2, 0, 1);
    SetSubitemState((void *)state[1], 4, (short)state[3], 1);
    state[2] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov164_TickTimerAdvanceSubState);
}
