/* State step: posts a pose, sends a state update, clears the timer and the swing flag, and installs
 * the wind-up step. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov181_TickWindupThenPickWait(void);

void Ov181_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 0xb, 0);
    Ov107_BuildAndSendUpdate(*state, 0x131, 4, state[1]);
    state[7] = 0;
    *(unsigned char *)((char *)state + 0x50) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov181_TickWindupThenPickWait);
}
