/* AI step: sends the debris update (0x138, mode 4) once its time comes and, when the animation
 * ends, posts pose 4 and continues with the falling debris. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov239_TickFallingDebris(void);

void Ov239_TimedRequestThenPose4(int *node) {
    int *state = (int *)node[1];
    state[0xb] += *(int *)(*node + 0x2c);
    if (*(unsigned char *)((char *)state + 0x32) == 0 && state[0xb] >= 0x2a8) {
        Ov107_BuildAndSendUpdate(*state, 0x138, 4, state[2]);
        *(unsigned char *)((char *)state + 0x32) = 1;
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    state[0xb] = 0;
    *(unsigned char *)((char *)state + 0x32) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov239_TickFallingDebris);
}
