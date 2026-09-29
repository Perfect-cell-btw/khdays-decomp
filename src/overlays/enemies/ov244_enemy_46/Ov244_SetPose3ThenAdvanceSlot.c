/* Play the anim (ov107 mode 3,1) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov244_ApproachTick(int);
void Ov244_SetPose3ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate((Actor *)(*(int *)*(int *)(param_1 + 4)), 3, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov244_ApproachTick);
}
