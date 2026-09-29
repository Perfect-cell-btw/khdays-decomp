/* Push animation params (4, 0) to the sprite, then dispatch via
 * SetIndexedSlot with handler Ov236_RidersB_AiFaceForwardQueue9. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_RidersB_AiFaceForwardQueue9(void);
void Ov236_SetPose4ThenAdvanceSlot_2(int param_1) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(param_1 + 4))), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_RidersB_AiFaceForwardQueue9);
}
