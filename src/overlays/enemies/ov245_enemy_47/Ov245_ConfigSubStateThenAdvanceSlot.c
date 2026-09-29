/* AI step: posts pose 5, sets stance bit 0x40, starts the strike animation, resets its counters and
 * continues with the double strike. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov245_DoubleStrikeTick(void);

void Ov245_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 5, 0);
    { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
      *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
    Ov107_StartAnim(*(int *)(*state + 0x3a0), 0, 0);
    state[0x10] = 0;
    *(unsigned char *)((char *)state + 0x48) = 0;
    *(unsigned char *)((char *)state + 0x49) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_DoubleStrikeTick);
}
