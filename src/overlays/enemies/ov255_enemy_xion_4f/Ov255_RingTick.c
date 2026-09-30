/* Ring tick of an ov255 state: the +0x50 timer accumulates the owner's rate and at 2.13 reaction
 * +0x3f8 mode 0x13 fires once at the +0x3b8 part's point (+0x65). Once the +0xc idle byte clears,
 * the nine +0x3f0 ring items are placed around that point at 2*pi/9 steps (Ov255_PlaceRingItem,
 * turned by the +0x1c orientation), animation 0x21 plays, the +0x3a4 part plays motion 0x1c,
 * reaction mode 0x14 fires at the point and the tick hands over to Ov255_GlideTick3. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void Ov255_PlaceRingItem(int item, void *at, void *q, int angle);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_GlideTick3(int *node);

void Ov255_RingTick(int *node)
{
    int *state = (int *)node[1];
    int i;

    state[0x14] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x65) == 0 && state[0x14] >= 0x2222) {
        Ov107_BuildAndSendUpdate(*state, (short)*(int *)(*state + 0x3f8), 0x13, (void *)(*(int *)(*state + 0x3b8) + 0x14));
        *((unsigned char *)state + 0x65) = 1;
    }
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    for (i = 0; i < 9; i++) {
        Ov255_PlaceRingItem(((int *)*(int *)(*state + 0x3f0))[i], (void *)(*(int *)(*state + 0x3b8) + 0x14), state + 7, i * 0x6488 / 9);
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0x21, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3a4), 0x1c, 0);
    Ov107_BuildAndSendUpdate(*state, (short)*(int *)(*state + 0x3f8), 0x14, (void *)(*(int *)(*state + 0x3b8) + 0x14));
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov255_GlideTick3);
}
