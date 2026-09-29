/* State step: once the model's animation ends, posts pose 4, loads the wait time of the current
 * slot and installs the countdown step. */

#include "game/enemy_common.h"

struct row3d4 { char _pad[0x3d4]; int f; };
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov145_CountdownTimer38ThenPose5(void);

void Ov145_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(*(int *)(*state + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*state), 4, 1);
    state[0xe] = ((struct row3d4 *)((int *)*state + state[0x12]))->f;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov145_CountdownTimer38ThenPose5);
}
