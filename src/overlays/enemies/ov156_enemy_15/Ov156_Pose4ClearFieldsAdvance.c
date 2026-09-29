/* State step: posts pose 4, clears the timer and the hit flags and installs the charge wind-up
 * step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov156_ChargeWindup();

void Ov156_Pose4ClearFieldsAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)n), 4, 0);
    *(int *)(n + 0x2c) = 0;
    *(char *)(n + 0x38) = 0;
    *(unsigned char *)(n + 0x39) &= ~2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov156_ChargeWindup);
}
