/* Ov245_PreAttackDelay -- pre-attack delay: counts the state's +0x24 timer up by the scene step;
 * at 0.3125 raises bit 0 of the actor's +0x60 high byte and bit 0 of the +0x388 item's +8 low
 * byte, plays pose 0, clears the +0x30 byte and moves the node to 020d1950. */
#include "nitro/types.h"
struct w8 { unsigned int lo : 8, rest : 24; };

extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_GlideTick(void);

void Ov245_PreAttackDelay(int *node) {
    int *state = (int *)node[1];

    state[9] += *(int *)(*node + 0x2c);
    if (state[9] < 0x500) {
        return;
    }
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 1) << 0x18) >> 0x10);
    }
    ((struct w8 *)(*(int *)(*state + 0x388) + 8))->lo |= 1;
    Ov107_PostTagUpdate(*state, 0, 0);
    *(unsigned char *)((char *)state + 0x30) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_GlideTick);
}
