/* Ov245_ReleaseHeld3a8 -- release the held sub-object at +0x3a8 (unless the actor's kind byte is 1
 * or nothing is held) and then run the base teardown. Sibling of Ov245_ReleaseHeldObject, which does
 * the same for +0x3a0 and has no base call. */

#include "game/enemy_common.h"

extern void TaskList_FinishByTag(int a, int b);

void Ov245_ReleaseHeld3a8(int self) {
    if (*(signed char *)(self + 0x1c6) != 1 && *(int *)(self + 0x3a8) != 0) {
        TaskList_FinishByTag(*(int *)(self + 0x3c), *(int *)(self + 0x3a8));
        *(int *)(self + 0x3a8) = 0;
    }
    Ov107_AiState_PostTickBase((char *)self);
}
