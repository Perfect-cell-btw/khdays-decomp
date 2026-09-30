/* AI step: counts the timer down and, when the model's animation ends, posts pose 0 and installs
 * the waypoint-wait step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov241_AiWaypointWait(void);

void Ov241_ConfigSubStateThenAdvanceSlot(int *node) {
    int *n0 = (int *)node[0];
    int *state = (int *)node[1];
    state[0xb] -= n0[0xb];
    if (*(unsigned char *)(*(int *)(*state + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*state), 0, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov241_AiWaypointWait);
}
