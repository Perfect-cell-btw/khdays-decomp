/* Clear +0x64/+0x94, kick the idle animation, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov252_WaitTick(int);
void Ov252_AiEnterIdleReset(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x64) = 0;
    *(signed char *)(owner + 0x94) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov252_WaitTick);
}
