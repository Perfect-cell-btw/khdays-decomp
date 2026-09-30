/* State step: derives the speed from the owner's frame step, posts tag 1, picks a random range
 * between the actor's limits at +0x224 and +0x228 and installs the trigger-when-in-range step. */

#include "game/enemy_common.h"
#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov151_TriggerWhenTargetInRange(void);
void Ov151_stateTimerRandomRange(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 5;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 1, 1);
    {
        int lo = *(int *)(*state + 0x224);
        int diff = *(int *)(*state + 0x228) - lo;
        if (diff < 0) diff = -diff;
        state[0xd] = lo + RandNextScaled(diff + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov151_TriggerWhenTargetInRange);
}
