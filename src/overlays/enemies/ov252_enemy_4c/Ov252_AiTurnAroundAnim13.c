/* Advance +0x54 by 0x3244, kick anim 0xd and the +0x574 sub-anim 0x12, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov252_DriftEntryTick(int);
void Ov252_AiTurnAroundAnim13(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x54) += 0x3244;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xd, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x574), 0x12, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov252_DriftEntryTick);
}
