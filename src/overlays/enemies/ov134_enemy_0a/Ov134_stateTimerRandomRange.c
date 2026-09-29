/* State step: derives the speed from the owner's frame step, posts tag 1, picks a random range
 * between the actor's limits at +0x224 and +0x228 and installs the idle step. */

#include "game/enemy_common.h"

extern int RandNextScaled(int bound);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov134_IdleTick(void);
void Ov134_stateTimerRandomRange(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[5] = v / 5;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 1, 1);
    {
        int lo = *(int *)(*state + 0x224);
        int diff = *(int *)(*state + 0x228) - lo;
        if (diff < 0) diff = -diff;
        state[0xc] = lo + RandNextScaled(diff + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov134_IdleTick);
}
