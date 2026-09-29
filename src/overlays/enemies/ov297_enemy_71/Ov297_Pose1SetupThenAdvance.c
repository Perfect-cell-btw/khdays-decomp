/* AI step: measures the target, posts pose 1, sets up the wander heading and timers and continues
 * with the wander tick. */

#include "game/enemy_common.h"

extern void Ov297_AcquireTargetGapAndAngle(void *node);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov297_WanderTick(void);

void Ov297_Pose1SetupThenAdvance(int node) {
    int *state = *(int **)(node + 4);

    Ov297_AcquireTargetGapAndAngle((void *)node);
    Ov107_PostTagUpdate((Actor *)(*state), 1, 0);
    state[0x14] = 0x900;
    state[0x22] = 0;
    state[0xc] = state[0xc] + state[0xa];
    state[0xd] = state[0xc];
    state[0x15] = 0x1fe0;
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), Ov297_WanderTick);
}
