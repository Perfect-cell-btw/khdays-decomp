/* Push animation params (4, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov119_AiQueue7OnAnimEnd. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov119_AiQueue7OnAnimEnd(void);
void Ov119_SetPose4ThenAdvanceSlot(int param_1) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(param_1 + 4))), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov119_AiQueue7OnAnimEnd);
}
