/* Unless the sub-object is busy, kick anim 9 on it, set +0x58 and dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov146_AiQueue7OnBothAnimsEnd(int);
void Ov146_AiDismountRiderWait(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)(owner + 8);
    if (*(unsigned char *)(*(int *)(obj + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)obj, 9, 0);
    *(int *)(owner + 0x58) = 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_AiQueue7OnBothAnimsEnd);
}
