/* AI step: posts pose 0xa, starts the animation, sends the attack update (0x137, mode 6) and
 * continues with the guard matrix step. */

#include "game/enemy_common.h"

extern void Ov220_startAnim(int a, int b);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov220_stateFixedAngleMatrix_3(void);

void Ov220_Action6AfterSubDispatch(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 0xa, 0);
    Ov220_startAnim(*state, 1);
    Ov107_BuildAndSendUpdate(*state, 0x137, 6, state[2]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov220_stateFixedAngleMatrix_3);
}
