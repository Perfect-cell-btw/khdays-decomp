/* Set the target rate (+0x48 = owner_rate*30/10), play the anim (ov107 mode 1) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_Reaction_ScaleThenBranch(int);
void Ov273_AiEnterScaleBranch(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x48) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 1, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_Reaction_ScaleThenBranch);
}
