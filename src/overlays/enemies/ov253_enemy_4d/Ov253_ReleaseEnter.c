/* Ov253_ReleaseEnter -- release entry: restores pose 1, clears bit 0 of the +0x3b4 item's +8
 * low byte, fires reaction 0x16c/8 at the +4 anchor, clears the +0x1c timer and the +0x30 flag
 * and moves the node to 020cf66c. */

#include "game/enemy_common.h"

struct w8 { unsigned int lo : 8, rest : 24; };

extern void Ov107_BuildAndSendUpdate(int actor, int id, int kind, void *anchor);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_ReleaseWaitTick(void);

void Ov253_ReleaseEnter(int *node) {
    int *state = (int *)node[1];

    Ov107_PostTagUpdate((Actor *)(*state), 1, 0);
    ((struct w8 *)(*(int *)(*state + 0x3b4) + 8))->lo &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0x16c, 8, (void *)state[1]);
    state[7] = 0;
    *((unsigned char *)state + 0x30) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_ReleaseWaitTick);
}
