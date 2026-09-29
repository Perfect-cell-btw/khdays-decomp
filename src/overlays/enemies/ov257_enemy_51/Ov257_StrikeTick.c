/* Strike tick of an ov257 state: the +0x54 timer accumulates the owner's rate; past 1.57, once
 * (+0x76), reaction +0x408 (as a halfword) mode 0xc fires at the +4 point; the +0x40 rate clears. Once the +0xc idle
 * byte clears, animation 0x12 plays, the +0x3d0 part plays motion 0xf, +0x73, the +0x44 timer and
 * the flag clear and the tick hands over to Ov257_WhirlTick. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_WhirlTick(int *node);

void Ov257_StrikeTick(int *node)
{
    int *state = (int *)node[1];

    state[0x15] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x76) == 0 && state[0x15] >= 0x1911) {
        Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x408), 0xc, (void *)state[1]);
        *((unsigned char *)state + 0x76) = 1;
    }
    state[0x10] = 0;
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0x12, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 0xf, 0);
    *((unsigned char *)state + 0x73) = 0;
    state[0x11] = 0;
    *((unsigned char *)state + 0x76) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_WhirlTick);
}
