/* State step: derives the speed from the owner's frame step, posts a pose, starts the effect
 * animation and installs the offset-tracking step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov195_AiTrackOffsetUntilAnimEnd_3(void);
void Ov195_stateAnimEffect(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[5] = v / 3;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0xe, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 6, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov195_AiTrackOffsetUntilAnimEnd_3);
}
