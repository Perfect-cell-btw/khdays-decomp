/* Kick the 7 animation on the object, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov146_ApproachTick_2(int);
void Ov146_AiEnterApproachB(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 7, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_ApproachTick_2);
}
