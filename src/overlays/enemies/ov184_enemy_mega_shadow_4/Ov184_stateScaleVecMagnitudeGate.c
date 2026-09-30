/* AI step: keeps the previous velocity and damps the current one by 0xb00; once it is almost still
 * (magnitude below 0x10) posts a pose and installs the queue-on-flag-clear step. */

#include "game/enemy_common.h"

struct v3 { int a, b, c; };
extern void ScaleVec3Fx12();
extern int VEC_Mag();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov184_AiQueue2OnFlagClear(void);
void Ov184_stateScaleVecMagnitudeGate(int *node) {
    int *state = (int *)node[1];
    *(struct v3 *)(state + 0x15) = *(struct v3 *)(state + 0x18);
    ScaleVec3Fx12(0xb00, state + 0x18, state + 0x18);
    if (VEC_Mag(state + 0x18) >= 0x10) return;
    Ov107_PostTagUpdate((Actor *)(*state), 10, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov184_AiQueue2OnFlagClear);
}
