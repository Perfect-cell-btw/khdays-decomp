/* Wind-up tick of an ov255 state: the +0x50 timer accumulates the owner's rate; past 0x333,
 * once (+0x65), reaction +0x3f8 (as a halfword) mode 0xb fires at the +4 point. Once the +0xc
 * idle byte clears, animation 0x11 plays, the flag clears and the tick hands over to
 * Ov255_StrikeTick. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_StrikeTick(int *node);

void Ov255_StrikeWindUpTick(int *node)
{
    int *state = (int *)node[1];

    state[0x14] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x65) == 0 && state[0x14] >= 0x333) {
        Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3f8), 0xb, (void *)state[1]);
        *((unsigned char *)state + 0x65) = 1;
    }
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0x11, 0);
    *((unsigned char *)state + 0x65) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov255_StrikeTick);
}
