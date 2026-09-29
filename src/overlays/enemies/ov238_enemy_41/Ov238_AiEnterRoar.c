/* When the parent's +0x390 slot is free and 020d0878 grants a slot, commit the launch (clear
 * +0x20/+0x2e, anim 2, 0x12e/8 timer, notify 020d2600, dispatch 020d1f54); otherwise latch 2. */

#include "game/enemy_common.h"

extern int Ov238_TargetGap(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov238_ForwardToAiTaskWhenReady(int);
extern int Ov238_StompTick(int);
void Ov238_AiEnterRoar(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(int *)(*(int *)(*(int *)owner + 0x384) + 0x390) != 0 || Ov238_TargetGap(param_1) == -1) {
        *(unsigned char *)(*(int *)owner + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        Ov238_TargetGap(param_1);
        *(int *)(owner + 0x20) = 0;
        *(unsigned char *)(owner + 0x2e) = 0;
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 2, 0);
        Ov107_BuildAndSendUpdate(*(int *)owner, 0x12e, 8, *(int *)(owner + 8));
        Ov238_ForwardToAiTaskWhenReady(*(int *)(*(int *)owner + 0x384));
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_StompTick);
    }
}
