/* AI step: when a target is in range, faces it, posts pose 6 and continues; otherwise ends the
 * step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *node, int idx, void *value);
extern int Ov220_DistanceToTarget(void *node);
extern void Ov220_AiStep_QueueAction4OnAnimEnd(void);

void Ov220_SetupGuardThenPose6(int node)
{
    int *state = *(int **)(node + 4);

    if (Ov220_DistanceToTarget((void *)node) < 0) {
        SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), 0);
        return;
    }

    state[3] = state[4];
    Ov107_PostTagUpdate((Actor *)(*state), 6, 0);
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), Ov220_AiStep_QueueAction4OnAnimEnd);
}
