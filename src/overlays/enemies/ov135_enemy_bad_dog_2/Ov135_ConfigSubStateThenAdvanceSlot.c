/* State step: once the model's animation ends, posts pose 5, starts the child selector's animation,
 * sets bit 0x40 in the high byte of the actor's flags and installs the swing step. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov135_SwingTick(void);

void Ov135_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*state), 5, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3a0), 1, 0);
    { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
      *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov135_SwingTick);
}
