/* AI step: once the actor touches ground or a wall, starts the action resource's animation, posts
 * pose 7, sends a state update and installs the scale step. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov204_TransformScaleThenAdvance(void);

struct sbit1 { unsigned char b : 1; };

void Ov204_Action6IfHitFlagsSet(int *node) {
    int *state = (int *)node[1];
    int s = *state;
    if (((struct sbit1 *)(s + 0x17a))->b == 0 && ((struct sbit1 *)(s + 0x17c))->b == 0)
        return;
    Ov107_StartAnim(*(int *)(s + 0x390), 2, 0);
    Ov107_PostTagUpdate((Actor *)(*state), 7, 0);
    Ov107_BuildAndSendUpdate(*state, 0x132, 6, state[9]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov204_TransformScaleThenAdvance);
}
