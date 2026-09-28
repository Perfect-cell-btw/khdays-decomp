#include "nitro/types.h"

extern int SetIndexedSlot(int self, int idx, void *handler);

/* Reaction reset: clear pActor field +0x388, set hw60 high-byte bit 0x80 then clear its bit 0,
 * re-arm the slot with no handler. hw60 = *(u16*)(*node+0x60), reloaded each op.
 * node=*(ReactionAiNode**)(self+4). */
void Ov260_ResetReactionFlags(int self) {
    int *node = *(int **)(self + 4);
    u16 hw;
    *(unsigned int *)(*node + 0x388) = 0;
    hw = *(u16 *)(*node + 0x60);
    *(u16 *)(*node + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x80) << 0x18) >> 0x10);
    hw = *(u16 *)(*node + 0x60);
    *(u16 *)(*node + 0x60) = (hw & ~0xff00) |
        (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~1) << 0x18) >> 0x10);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
}
