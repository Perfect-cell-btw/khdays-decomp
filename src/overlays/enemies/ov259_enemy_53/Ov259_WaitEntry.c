/* Wait entry of the ov259 actor: the +0x68 timer, +0x60 and the +0xac cue flags clear, +0x94 = 30,
 * bit 6 of the actor's +0x60 high byte is set, pose 0xf plays on the actor and its partner
 * (020cd524) and the node moves on to 020cf0bc. */

#include "nitro/types.h"

extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void Ov259_MirrorPartnerPose(int *node, int pose, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_HoverTick(void);

void Ov259_WaitEntry(int *node)
{
    int *state = (int *)node[1];

    state[0x1a] = 0;
    state[0x18] = 0;
    *((u8 *)state + 0xac) = 0;
    state[0x25] = 0x1e;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate(*state, 0xf, 0);
    Ov259_MirrorPartnerPose(node, 0xf, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_HoverTick);
}
