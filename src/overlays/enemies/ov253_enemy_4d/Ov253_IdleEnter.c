/* Ov253_IdleEnter -- idle entry: sets pose 0 (flag 1), arms the +0x1c timer with 5.0 plus a
 * random 5.0, raises bit 0 of the +0x3b4 item's +8 low byte, clears the actor's +0x3bc and moves
 * the node to 020cf3d8. */

#include "game/enemy_common.h"

struct w8 { unsigned int lo : 8, rest : 24; };

extern int RandNextScaled(int scale);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_IdleTick(void);

void Ov253_IdleEnter(int *node) {
    int *state = (int *)node[1];

    Ov107_PostTagUpdate((Actor *)(*state), 0, 1);
    state[7] = RandNextScaled(0x5001) + 0x5000;
    ((struct w8 *)(*(int *)(*state + 0x3b4) + 8))->lo |= 1;
    *(int *)(*state + 0x3bc) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_IdleTick);
}
