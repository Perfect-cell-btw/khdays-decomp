/* Accumulate the owner rate (+0x2c) into the child timer (+0x5c); once it reaches
 * 0x6ee, clear flag 7 in the high byte at (*child)+0x60, stop the anim, and dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov222_AiRollTimerOnAnimEnd(void);
struct hi_020d1d28 { unsigned short pad : 8; unsigned short flags : 8; };
void Ov222_WaitThenAdvanceState(int param_1) {
    int child = *(int *)(param_1 + 4);
    int c = *(int *)(child + 0x5c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x5c) = c;
    if (c < 0x6ee) return;
    ((struct hi_020d1d28 *)(*(int *)child + 0x60))->flags &= ~0x80;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov222_AiRollTimerOnAnimEnd);
}
