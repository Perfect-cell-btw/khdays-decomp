/* State step: once the model's animation ends, posts pose 7, starts the child selector's animation
 * and installs the advance step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov144_AdvanceTick(void);

void Ov144_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(*(int *)(*state + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*state), 7, 1);
    Ov107_StartAnim(*(int *)(*state + 0x394), 1, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_AdvanceTick);
}
