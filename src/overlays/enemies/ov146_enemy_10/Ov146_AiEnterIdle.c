/* Kick anim 1 on the body; if the +0x58 slot is live, kick anim 1 on the child and step it;
 * seed +0x3c and dispatch 020cd138. */

#include "game/enemy_common.h"

extern int Ov146_ForwardToAiTaskWhenReady(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov146_AiIdleCountdown(int);
void Ov146_AiEnterIdle(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 1);
    if (*(int *)(owner + 0x58) != 0) {
        Ov107_PostTagUpdate((Actor *)(*(int *)(owner + 8)), 1, 1);
        Ov146_ForwardToAiTaskWhenReady(*(int *)(owner + 8));
    }
    *(int *)(owner + 0x3c) = 0x1000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_AiIdleCountdown);
}
