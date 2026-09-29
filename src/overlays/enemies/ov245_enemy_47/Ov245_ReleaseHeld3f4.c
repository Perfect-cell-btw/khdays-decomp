/* Ov245_ReleaseHeld3f4 -- release the held sub-object at +0x3f4 (unless the actor's kind byte is
 * 4 or nothing is held), zero the +0x3a4 placement's scale, then run the base teardown. */

#include "game/enemy_common.h"

extern void TaskList_FinishByTag(int a, int b);
extern void Srt_SetScaleUniform(void *srt, int scale);

void Ov245_ReleaseHeld3f4(int self) {
    if (*(signed char *)(self + 0x1c6) != 4 && *(int *)(self + 0x3f4) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(self + 0x3f4));
        *(int *)(self + 0x3f4) = 0;
        Srt_SetScaleUniform((void *)(self + 0x3a4), 0);
    }
    Ov107_AiState_PostTickBase((char *)self);
}
