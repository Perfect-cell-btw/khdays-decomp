/* Accumulate the owner rate (+0x2c) into the child timer (+0x4c); once it reaches
 * 0x666, stop the anim, run Ov229_startAnim, reset the timer, and dispatch. */

#include "game/enemy_common.h"

extern void Ov229_startAnim(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov229_AiMoveUntilAnimEnd(void);
void Ov229_TickTimerReleaseAtThreshold(int param_1) {
    int child = *(int *)(param_1 + 4);
    int c = *(int *)(child + 0x4c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x4c) = c;
    if (c < 0x666) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 0);
    Ov229_startAnim(*(int *)child, 0);
    *(int *)(child + 0x4c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov229_AiMoveUntilAnimEnd);
}
