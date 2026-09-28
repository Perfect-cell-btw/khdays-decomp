/* Down tick of the ov259 actor: the +0x68 timer accumulates the frame rate; with no health left
 * (+0x21a) bits 0-1 of +0x1ae are set; the cue pulses once at 0x3b8 (020cd2c8 2, +0xac bit 0).
 * Past 0x550 the timer restarts, pose 0x1b plays and the node moves on to 020cfce4. */

#include "nitro/types.h"

extern void Ov259_MapHeldItemKindToAnim(int actor, int flag);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_AiFinisherTick(void);

void Ov259_DownTick(int *node)
{
    int *state = (int *)node[1];

    state[0x1a] += *(int *)(node[0] + 0x2c);
    if (*(short *)(*state + 0x200 + 0x1a) <= 0) {
        *(u16 *)(*state + 0x100 + 0xae) |= 3;
    }
    if ((*((u8 *)state + 0xac) & 1) == 0 && state[0x1a] >= 0x3b8) {
        *((u8 *)state + 0xac) |= 1;
        Ov259_MapHeldItemKindToAnim(*state, 2);
    }
    if (state[0x1a] <= 0x550) {
        return;
    }
    state[0x1a] = 0;
    Ov107_PostTagUpdate(*state, 0x1b, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_AiFinisherTick);
}
