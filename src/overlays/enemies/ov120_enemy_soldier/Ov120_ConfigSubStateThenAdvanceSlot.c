/* State step: posts pose 4, clears the timer and the one-shot flags, sends a state update and
 * installs the area-attack step. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov120_AreaAttack_Broadcast(void);

void Ov120_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    state[0x10] = 0;
    *(unsigned char *)((char *)state + 0x4c) = 0;
    *(unsigned char *)((char *)state + 0x4d) = 0;
    Ov107_BuildAndSendUpdate(*state, 0x11a, 7, state[3]);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov120_AreaAttack_Broadcast);
}
