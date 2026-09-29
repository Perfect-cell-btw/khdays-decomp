/* AI step: unless in state 10, switches the model's sub-items to their finishing states and
 * continues with finishing. */

#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov131_FinishIfSubFlagClear(void);

void Ov131_stateSubitemStateTransition(char *obj) {
    int *state = *(int **)(obj + 4);
    if (*(signed char *)(*state + 0x310) == 10) return;
    SetSubitemState((void *)state[1], 2, 1, 0);
    SetSubitemState((void *)state[1], 0, 2, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov131_FinishIfSubFlagClear);
}
