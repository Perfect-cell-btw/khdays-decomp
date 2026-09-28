/* Wait tick of the ov245 enemy: once the +4 rig is idle the +0x28 clock runs; after 8.5, unless the
 * +0x438 partner is in state 6 with its +0x384 rig still busy, the +0xc velocity becomes (0, 0, 0.25),
 * the +0x14 speed 0.25, the partner is marked (+0x1ae bit 0) and the node moves to 020ce4e0. */
#include "nitro/types.h"

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_RiseTick(void);

void Ov245_WaitTick(int *node)
{
    int *state = (int *)node[1];
    int partner;

    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    state[0xa] += *(int *)(node[0] + 0x2c);
    if (state[0xa] < 0x8800) {
        return;
    }
    partner = *(int *)(*state + 0x438);
    if (*(signed char *)(partner + 0x300 + 0x10) == 6 && *(unsigned char *)(*(int *)(partner + 0x384) + 0xad) != 0) {
        return;
    }
    state[6] = 0;
    state[7] = 0;
    state[5] = state[8] = 0x400;
    *(u16 *)(partner + 0x100 + 0xae) |= 1;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_RiseTick);
}
