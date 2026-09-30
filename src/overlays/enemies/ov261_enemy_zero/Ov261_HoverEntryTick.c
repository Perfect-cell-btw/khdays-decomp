/* Hover entry tick of the ov261 enemy (and its byte-identical twin): the +0x3c speed is fifteen
 * frame-times, the +0x1c anchor follows the +0x3a8 part's +0x74 position, the +0x30 jitter
 * vector is re-rolled in [-0x100, 0x100] and after 0x1000 of accumulated frame-time the state
 * ends with sub-state 4. */

#include "nitro/types.h"
#include "game/engine.h"

extern void Ov261_SetFacingAnchor(void *anchor, void *pos, int *target);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov261_HoverEntryTick(int *node)
{
    int *state = (int *)node[1];

    state[0xf] = *(int *)(*node + 0x2c) * 30 / 2;
    Ov261_SetFacingAnchor(state + 7, (void *)(*(int *)(*state + 0x3a8) + 0x74), (int *)state[1]);
    state[0xc] = RandNextScaled(0x201) - 0x100;
    state[0xd] = RandNextScaled(0x201) - 0x100;
    state[0xe] = RandNextScaled(0x201) - 0x100;
    state[0x10] += *(int *)(*node + 0x2c);
    if (state[0x10] < 0x1000) {
        return;
    }
    *(u8 *)(*state + 0x1c7) = 4;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
