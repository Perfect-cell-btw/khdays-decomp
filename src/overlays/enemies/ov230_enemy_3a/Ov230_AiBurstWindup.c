/* Poll 020d303c: on failure dispatch, otherwise retire the live node via 020d2d90, and while not
 * busy kick anim 0x11 and tick +0x61; once +0x61 reaches 3 advance to 020d4de8. */

#include "game/enemy_common.h"

extern int Ov230_MeasureTargetGap(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov230_ContactCheck(int);
extern int Ov230_Burst(int);
void Ov230_AiBurstWindup(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov230_MeasureTargetGap(param_1) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        if (*(int *)(owner + 8) != 0) {
            Ov230_ContactCheck(owner);
            *(int *)(owner + 8) = 0;
        }
        if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) == 0) {
            Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x11, 0);
            *(unsigned char *)(owner + 0x61) += 1;
        }
        if (*(unsigned char *)(owner + 0x61) < 3) return;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov230_Burst);
    }
}
