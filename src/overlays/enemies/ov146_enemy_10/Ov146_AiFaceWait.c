/* While the +0x40 timer is positive wait; otherwise kick anim 6 and dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov146_FaceTick(int);
void Ov146_AiFaceWait(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(int *)(owner + 0x40) > 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 6, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_FaceTick);
}
