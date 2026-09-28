/* Restart entry of the ov259 lunge: the +0x54, +0x68 and +0x98 counters and the +0xac cue flags
 * clear, bits 2 and 6 of the actor's +0x60 high byte are set, pose 0xf plays on the actor and its
 * partner (020cd524) and the node moves on to 020d0e34. */
#include "nitro/types.h"

extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void Ov259_MirrorPartnerPose(int *node, int pose, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_RiseTick_2(void);

void Ov259_LungeRestartEntry(int *node)
{
    int *state = (int *)node[1];

    state[0x15] = 0;
    state[0x1a] = 0;
    *((u8 *)state + 0xac) = 0;
    state[0x26] = 0;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x44) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate(*state, 0xf, 0);
    Ov259_MirrorPartnerPose(node, 0xf, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_RiseTick_2);
}
