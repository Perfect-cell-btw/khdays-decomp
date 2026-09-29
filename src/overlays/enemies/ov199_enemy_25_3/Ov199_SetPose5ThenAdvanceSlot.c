/* Kick the 5 animation on the object, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov199_CopyScaleVec3ThenAdvanceSlot(int);
void Ov199_SetPose5ThenAdvanceSlot(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 5, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov199_CopyScaleVec3ThenAdvanceSlot);
}
