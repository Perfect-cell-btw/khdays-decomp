/* Kick the 0/1 animation, set +0x14, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov218_AiIdleCountdown(int);
void Ov218_AiEnterIdle(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0, 1);
    *(int *)(owner + 0x14) = 0x1000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov218_AiIdleCountdown);
}
