/* Kick anim (1 if +0x58 set else 7, phase 1), then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov146_ApproachTick(int);
void Ov146_AiEnterApproach(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), *(int *)(owner + 0x58) != 0 ? 1 : 7, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_ApproachTick);
}
