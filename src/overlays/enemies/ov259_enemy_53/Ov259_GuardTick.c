/* Guard tick of the ov259 actor: the +0x68 timer accumulates the frame rate and the aim refreshes
 * (020cdcac). While guarding (+0x44) bits 0-1 of +0x1ae are set; otherwise past the +0x64 limit
 * pose 7 plays and the node moves on to 020cfe0c. */

#include "nitro/types.h"

extern void Ov259_RefreshAim(int *node);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_AiFinisherEnd(void);

void Ov259_GuardTick(int *node)
{
    int *state = (int *)node[1];

    state[0x1a] += *(int *)(node[0] + 0x2c);
    Ov259_RefreshAim(node);
    if (state[0x11] != 0) {
        *(u16 *)(*state + 0x100 + 0xae) |= 3;
        return;
    }
    if (state[0x1a] <= state[0x19]) {
        return;
    }
    Ov107_PostTagUpdate(*state, 7, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_AiFinisherEnd);
}
