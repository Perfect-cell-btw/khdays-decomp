/* Ov253_ChargeEnter -- charge entry: raises bit 0 of the actor's +0x1ae, sets pose 2, raises
 * bit 0 of the +0x60 high byte, fires reaction 0x16c/7 at the +4 anchor and moves the node to
 * 020cf2c0. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int actor, int id, int kind, void *anchor);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_ChargeWaitTick(void);

void Ov253_ChargeEnter(int *node) {
    int *state = (int *)node[1];

    *(u16 *)(*state + 0x100 + 0xae) |= 1;
    Ov107_PostTagUpdate((Actor *)(*state), 2, 0);
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 1) << 0x18) >> 0x10);
    }
    Ov107_BuildAndSendUpdate(*state, 0x16c, 7, (void *)state[1]);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_ChargeWaitTick);
}
