/* State step: posts a pose, sets bit 0x40 in the high byte of the actor's flags (+0x60), clears the
 * timer and a sweep flag, and installs the timed transform step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov251_stateTimerTransformVec(void);
void Ov251_stateAnimSetFlagClear(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 0xd, 0);
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    state[0x1b] = 0;
    *(unsigned char *)((char *)state + 0x51) &= ~2;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov251_stateTimerTransformVec);
}
