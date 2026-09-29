/* Dock entry of an ov260 helper: its owner is marked busy (+0x388), bit 7 of the +0x60 high byte
 * drops and bit 0 is set, pose 0 plays, +0xc and the +0x10 flag clear and the node moves on to
 * 020d2888. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov260_BeamTick(void);

void Ov260_HelperDockEntry(int *node)
{
    int *state = (int *)node[1];

    *(int *)(*state + 0x388) = 1;
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            (((unsigned int)(u16)((((unsigned int)hw << 0x10) >> 0x18) & ~0x80) << 0x18) >> 0x10);
    }
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 1) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0, 0);
    state[3] = 0;
    *((u8 *)state + 0x10) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov260_BeamTick);
}
