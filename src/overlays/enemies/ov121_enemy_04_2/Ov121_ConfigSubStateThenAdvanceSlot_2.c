/* State step: posts pose 5, sets bit 0x40 in the high byte of the actor's flags, starts the child
 * selector's animation, clears the timer and the one-shot flags and installs the sweep-attack step.
 */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov121_SweepAttack_Step(void);

void Ov121_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 5, 0);
    { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
      *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
    Ov107_StartAnim(*(int *)(*state + 0x3a0), 0, 0);
    state[0x10] = 0;
    *(unsigned char *)((char *)state + 0x4c) = 0;
    *(unsigned char *)((char *)state + 0x4d) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov121_SweepAttack_Step);
}
