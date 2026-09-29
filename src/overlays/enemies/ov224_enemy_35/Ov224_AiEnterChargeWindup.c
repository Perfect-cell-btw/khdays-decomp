/* If Ov224_MeasureTargetGap fails (<0), dispatch with a null handler and return;
 * else set anim (8 if child+0x78 else 0xc), clear +0x76/+0x75/+0x5c, dispatch. */

#include "game/enemy_common.h"

extern int Ov224_MeasureTargetGap(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov224_ChargeWindupTick(void);
void Ov224_AiEnterChargeWindup(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (Ov224_MeasureTargetGap(param_1, 0) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*(int *)child), *(int *)(child + 0x78) != 0 ? 8 : 0xc, 0);
    *(unsigned char *)(child + 0x76) = 0;
    *(unsigned char *)(child + 0x75) = 0;
    *(int *)(child + 0x5c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov224_ChargeWindupTick);
}
