/* Pose the actor (ov107 mode 2,1), run the local setup (mode 1) and register the handler. */

#include "game/enemy_common.h"

extern void Ov233_startAnim(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov233_AiApproachTick(int);
void Ov233_AiEnterApproach(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 2, 1);
    Ov233_startAnim(*(int *)child, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov233_AiApproachTick);
}
