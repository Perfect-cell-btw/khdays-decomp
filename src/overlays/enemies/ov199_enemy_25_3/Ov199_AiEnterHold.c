/* Kick the 1/0 animation, set +0x40, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov199_TickCountdownOrEnterSubState4(int);
void Ov199_AiEnterHold(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 0);
    *(int *)(owner + 0x40) = 0x2000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov199_TickCountdownOrEnterSubState4);
}
