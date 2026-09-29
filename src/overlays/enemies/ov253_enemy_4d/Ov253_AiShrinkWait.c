/* Count the +0x1c timer up; past 0x2000 kick anim 3 and dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AiShrinkEnd(int);
void Ov253_AiShrinkWait(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(owner + 0x1c) + *(int *)(a + 0x2c);
    *(int *)(owner + 0x1c) = t;
    if (t < 0x2000) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 3, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiShrinkEnd);
}
