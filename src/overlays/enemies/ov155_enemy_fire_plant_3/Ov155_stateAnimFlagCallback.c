/* State step: posts pose 3, sets flag 0x40 of +0x1ae, clears the timer and its flag, derives the
 * speed from the owner's frame step, sends the animation pair from the overlay's table to the
 * actor's event callback and installs the aim step. */

#include "game/enemy_common.h"

struct pair { unsigned short a, b; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern struct pair data_ov155_020d58e0;
extern void Ov155_AimTick(void);
void Ov155_stateAnimFlagCallback(int *node) {
    int *state = (int *)node[1];
    struct pair buf;
    void (*cb)();
    Ov107_PostTagUpdate((Actor *)(*state), 3, 0);
    *(unsigned short *)(*state + 0x1ae) |= 0x40;
    state[7] = 0;
    *(signed char *)((char *)state + 0x24) = 0;
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[8] = v / 40;
    }
    buf = data_ov155_020d58e0;
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, &buf, 4);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov155_AimTick);
}
