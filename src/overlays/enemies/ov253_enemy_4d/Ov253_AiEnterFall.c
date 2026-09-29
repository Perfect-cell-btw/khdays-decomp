/* Reset the motion fields, latch +0x454, kick anim 0xb, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AnimWaitTick(int);
void Ov253_AiEnterFall(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x34) = 0;
    *(int *)(owner + 0x1c) = 0;
    *(signed char *)(owner + 0x38) = 1;
    *(int *)(*(int *)owner + 0x454) = 1;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xb, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AnimWaitTick);
}
