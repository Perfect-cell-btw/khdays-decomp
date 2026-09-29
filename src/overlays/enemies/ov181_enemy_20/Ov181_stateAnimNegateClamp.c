/* State step: posts a pose, mirrors the sweep (negates its two rates and keeps the third
 * non-positive) and installs the steering sweep step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov181_BeginSteerSweep(void);
void Ov181_stateAnimNegateClamp(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 0x11, 0);
    state[0x1e] = -state[0x1e];
    state[0x20] = -state[0x20];
    if (state[0x1f] > 0) state[0x1f] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov181_BeginSteerSweep);
}
