/* Play the anim (ov107 mode 2) on *child and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov254_AiStep_QueueAction0OnAnimEnd_4(int);
void Ov254_SetPose2ThenAdvanceSlot_2(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 2, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_AiStep_QueueAction0OnAnimEnd_4);
}
