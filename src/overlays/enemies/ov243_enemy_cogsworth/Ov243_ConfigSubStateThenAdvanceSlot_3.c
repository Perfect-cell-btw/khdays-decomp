/* State step: posts tag 1, starts the child selector's walk animation, clears the step flag and
 * installs the walk step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov243_WalkTick(void);

void Ov243_ConfigSubStateThenAdvanceSlot_3(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 1, 1);
    Ov107_StartAnim(*(int *)(*state + 0x390), 0, 1);
    *(unsigned char *)((char *)state + 0x40) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov243_WalkTick);
}
