/* Charge decision of the ov144 enemy (and its byte-identical twin): with a +0x39c target and a
 * +0x3b8 anchor and the +0x40 charge at or below 0x100 the tick hands off to cd450 directly;
 * otherwise (no target/anchor, or charge above 0x100) the actor plays animation 0 and hands off
 * to cd41c. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov144_BranchInvokeOrCopySlotThenAdvance(int *node);
extern void Ov144_AiCountdownThenBranch(int *node);

void Ov144_ChargeDecision(int *node)
{
    int *state = (int *)node[1];
    int actor = *state;

    if (*(int *)(actor + 0x39c) != 0 && *(int *)(actor + 0x3b8) != 0) {
        if (state[0x10] <= 0x100) {
            SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_BranchInvokeOrCopySlotThenAdvance);
            return;
        }
        Ov107_PostTagUpdate((Actor *)actor, 0, 1);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_AiCountdownThenBranch);
        return;
    }
    Ov107_PostTagUpdate((Actor *)actor, 0, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_BranchInvokeOrCopySlotThenAdvance);
}
