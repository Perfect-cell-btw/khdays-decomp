/* AI step: once the model's animation ends, posts pose 7, clears the timer and installs the timed
 * step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov136_AiStep_WaitTimerThenTag8();
void Ov136_stIdlePose7ClearTimerAdvance(int param_1)
{
    int *state = *(int **)(param_1 + 4);
    if (*(unsigned char *)(state[1] + 0xad) != 0)
        return;
    Ov107_PostTagUpdate((Actor *)state[0], 7, 1);
    state[0xc] = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), Ov136_AiStep_WaitTimerThenTag8);
}
