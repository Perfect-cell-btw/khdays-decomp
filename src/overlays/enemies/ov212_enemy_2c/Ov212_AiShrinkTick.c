/* Ease the +0x57c value toward 0; once within threshold run 020ce404, kick anim 8 and dispatch. */

#include "game/enemy_common.h"

extern int Ov212_FlagSlotsDirty(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov212_AiStep_QueueAction2OnAnimEnd(int);
void Ov212_AiShrinkTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int v = *(int *)(*(int *)owner + 0x57c);
    *(int *)(*(int *)owner + 0x57c) = v + (-v * 0x180) / 0x1000;
    if (*(int *)(*(int *)owner + 0x57c) > 0x1b3) return;
    Ov212_FlagSlotsDirty(owner);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 8, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_AiStep_QueueAction2OnAnimEnd);
}
