/* AI step: once the actor touches ground or a wall, starts the sweep animation, posts pose 8, sends
 * a state update, clears the hit flag and timer and installs the sweep step. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov205_SweepTick(void);

struct sbit1 { unsigned char b : 1; };

void Ov205_Action7IfHitFlagsSet(int *node) {
    int *state = (int *)node[1];
    int s = *state;
    if (((struct sbit1 *)(s + 0x17a))->b == 0 && ((struct sbit1 *)(s + 0x17c))->b == 0)
        return;
    Ov107_StartAnim(*(int *)(s + 0x390), 3, 0);
    Ov107_PostTagUpdate((Actor *)(*state), 8, 0);
    Ov107_BuildAndSendUpdate(*state, 0x132, 7, state[8]);
    *((char *)state + 0x44) = 0;
    state[0xb] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov205_SweepTick);
}
