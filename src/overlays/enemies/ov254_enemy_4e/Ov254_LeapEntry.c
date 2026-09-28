/* Move entry: the actor's +0x390 latch is set, bits 1-3 and 7 of its +0x60 high byte and bit 0
 * of +0x1ae are set, pose 0 plays, reaction 0x16d/9 fires at the +0x18 point, the +0x30 vector
 * clears and the node moves to 020d34ac. */
#include "nitro/types.h"

extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov254_HoverTick(void);

void Ov254_LeapEntry(int *node)
{
    int *state = (int *)node[1];

    *(int *)(*state + 0x390) = 1;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x8e) << 0x18) >> 0x10);
    }
    *(u16 *)(*state + 0x100 + 0xae) |= 1;
    Ov107_PostTagUpdate(*state, 0, 0);
    Ov107_BuildAndSendUpdate(*state, 0x16d, 9, (void *)state[6]);
    state[0xc] = 0;
    state[0xd] = 0;
    state[0xe] = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov254_HoverTick);
}
