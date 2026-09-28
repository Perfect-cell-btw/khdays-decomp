/* Brain start of the ov237 actor: move 1 with no next move, kind 1, the +0x38 point is the actor's
 * +0xb0 pose, bits 1-2 of the +0x60 high byte are set and the three brain slots get 020ce378 (1),
 * 020cd554 (0) and 020cdda8 (2). */

#include "nitro/types.h"

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov237_StartMove(void);
extern void Ov237_MoveDispatch(void);
extern void Ov237_PairTick(void);

void Ov237_BrainStart(int *node)
{
    int *state = (int *)node[1];

    *(signed char *)(*state + 0x1c6) = 1;
    *(signed char *)(*state + 0x1c7) = -1;
    *(unsigned char *)(*state + 0x1c9) = 1;
    state[0xe] = *state + 0xb0;
    {
        u16 hw = *(u16 *)(*state + 0x60);

        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 6) << 0x18) >> 0x10);
    }
    SetIndexedSlot(node, 1, Ov237_StartMove);
    SetIndexedSlot(node, 0, Ov237_MoveDispatch);
    SetIndexedSlot(node, 2, Ov237_PairTick);
}
