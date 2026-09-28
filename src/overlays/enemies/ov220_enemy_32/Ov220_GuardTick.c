/* Guard tick of the ov220 enemy: the +0x14 timer accumulates the frame-time; at 0x7000 with
 * the +0x3e flag clear, the +4 item's +0xa8 byte is cleared and the flag set. Once the item is
 * idle the actor plays animation 12 and hands off to the next guard state. */
#include "nitro/types.h"

extern void Ov107_PostTagUpdate(int actor, int anim, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov220_AiStep_QueueAction2OnAnimEnd(int *node);

void Ov220_GuardTick(int *node)
{
    int *state = (int *)node[1];

    state[5] += *(int *)(*node + 0x2c);
    if (*(u8 *)((char *)state + 0x3e) == 0 && state[5] >= 0x7000) {
        *(u8 *)(state[1] + 0xa8) = 0;
        *(u8 *)((char *)state + 0x3e) = 1;
    }
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0xc, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov220_AiStep_QueueAction2OnAnimEnd);
}
