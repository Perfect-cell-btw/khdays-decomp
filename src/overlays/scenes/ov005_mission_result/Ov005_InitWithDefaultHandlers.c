/* Zero a 0xc-byte record, then set its +4/+8 handler slots from the source pair, falling back to
 * the default handlers 020342e8 / 020343cc when a slot is null. */

#include "game/engine.h"

extern void MI_CpuFill8(void *dst, int val, int size);
void Ov005_InitWithDefaultHandlers(int param_1, int param_2) {
    int v;
    MI_CpuFill8((void *)param_1, 0, 0xc);
    v = *(int *)param_2;
    *(int *)(param_1 + 4) = v ? v : (int)&MsgDb_FetchRecord;
    v = *(int *)(param_2 + 4);
    *(int *)(param_1 + 8) = v ? v : (int)&DispatchByNodeKind;
}
