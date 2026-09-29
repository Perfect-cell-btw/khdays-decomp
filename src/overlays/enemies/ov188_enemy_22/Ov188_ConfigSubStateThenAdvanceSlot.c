/* State step: posts a pose, sends a state update, clears the timer and the two hit flags, and
 * installs the wind-up step. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov188_WindUpCharge(void);

void Ov188_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    Ov107_BuildAndSendUpdate(*state, 0x12f, 7, state[3]);
    state[6] = 0;
    *(unsigned char *)((char *)state + 0x3c) = 0;
    *(unsigned char *)((char *)state + 0x3d) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov188_WindUpCharge);
}
