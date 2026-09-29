/* State step: posts pose 3, clears the timer and hit flags, derives the speed from the owner's
 * frame step, sends the animation pair from the overlay's table to the actor's event callback and
 * installs the throw wind-up step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov157_020d0bb0[];
extern void Ov157_ThrowWindup(void);
void Ov157_stateAnimIndirectCallback(int *node) {
    int *state = (int *)node[1];
    unsigned short pair[2];
    unsigned short *pp;
    void (*cb)();
    Ov107_PostTagUpdate((Actor *)(*state), 3, 0);
    state[0xb] = 0;
    *(signed char *)((char *)state + 0x38) = 0;
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[0xc] = v / 5;
    }
    pp = pair;
    pp[1] = data_ov157_020d0bb0[1];
    pp[0] = data_ov157_020d0bb0[0];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov157_ThrowWindup);
}
