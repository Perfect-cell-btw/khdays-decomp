/* Unless busy, tick +0x54: on 8 kick anim 0x11, clear +0x4c/+0x6a and dispatch, otherwise just
 * clear +0x6a and kick anim 0x10. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_AiClawsReturnWait(int);
void Ov256_AiChargeRepeat(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(int *)(owner + 0x54) += 1;
    if (*(int *)(owner + 0x54) == 8) {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x11, 0);
        *(int *)(owner + 0x4c) = 0;
        *(unsigned char *)(owner + 0x6a) = 0;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_AiClawsReturnWait);
    } else {
        *(unsigned char *)(owner + 0x6a) = 0;
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x10, 0);
    }
}
