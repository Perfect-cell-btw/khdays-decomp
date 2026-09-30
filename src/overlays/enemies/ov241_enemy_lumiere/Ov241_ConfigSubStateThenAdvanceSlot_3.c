/* State step: posts pose 4, sends a state update, clears the step flag and installs the target-hook
 * step. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov241_CallTargetHook(void);

void Ov241_ConfigSubStateThenAdvanceSlot_3(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    Ov107_BuildAndSendUpdate(*state, 0x13a, 5, state[3]);
    *(unsigned char *)((char *)state + 0x40) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov241_CallTargetHook);
}
