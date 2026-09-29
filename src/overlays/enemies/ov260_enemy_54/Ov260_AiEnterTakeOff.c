/* Kick the primary anim 1 and the +0x428 sub-anim 0, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov260_ApproachTick(int);
void Ov260_AiEnterTakeOff(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x428), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov260_ApproachTick);
}
