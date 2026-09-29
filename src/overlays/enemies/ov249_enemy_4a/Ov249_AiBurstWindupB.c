/* Poll 020d10b4: on failure dispatch, otherwise if +8 is live force +0x61 to 0xff and clear +8;
 * while not busy kick anim 0x11 and tick +0x61; once it reaches 3 advance to 020d2ea8. */

#include "game/enemy_common.h"

extern int Ov249_MeasureTargetGap(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov249_Burst(int);
void Ov249_AiBurstWindupB(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov249_MeasureTargetGap(param_1) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        if (*(int *)(owner + 8) != 0) {
            *(unsigned char *)(owner + 0x61) = 0xff;
            *(int *)(owner + 8) = 0;
        }
        if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) == 0) {
            Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x11, 0);
            *(unsigned char *)(owner + 0x61) += 1;
        }
        if (*(unsigned char *)(owner + 0x61) < 3) return;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov249_Burst);
    }
}
