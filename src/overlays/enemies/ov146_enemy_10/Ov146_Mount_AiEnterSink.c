/* Kick anim 2, clear bit 1 of the child's +0x5c flags, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov146_Mount_AiSinkWait(int);
void Ov146_Mount_AiEnterSink(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 2, 0);
    *(int *)(*(int *)(owner + 8) + 0x5c) &= ~2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_Mount_AiSinkWait);
}
