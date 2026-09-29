/* State step: posts pose 2, resets the pose vectors, picks a random delay between the actor's
 * limits at +0x224 and +0x228 and installs the steer-toward-target step. */

#include "game/enemy_common.h"
#include "game/engine.h"

extern void Ov215_loadDefaultPoseVecs();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov215_SteerTowardTarget(void);

void Ov215_stEnterRandDelay(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 2, 1);
    Ov215_loadDefaultPoseVecs(*state, 0);
    {
        int lo = *(int *)(*state + 0x224);
        int hi = *(int *)(*state + 0x228);
        int d = hi - lo;
        if (d < 0) d = -d;
        state[0x14] = lo + RandNextScaled(d + 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov215_SteerTowardTarget);
}
