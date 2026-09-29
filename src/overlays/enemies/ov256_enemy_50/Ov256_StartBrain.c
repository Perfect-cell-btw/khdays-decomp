/* Start of the ov256 actor's brain: move 1 is current and none pending (+0x1c6 = 1, +0x1c7 = -1), the
 * idle time +0x50 is rolled between the +0x224 / +0x228 bounds, +0xc points at the +0xb0 anchor and
 * the three slots take the think (020cd430), watch (020cd8f0) and facing (020cd740) handlers. */

#include "game/engine.h"

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov256_AiDispatchAction(void);
extern void Ov256_EnterState(void);
extern void Ov256_Update(void);

void Ov256_StartBrain(int *node)
{
    int *state = (int *)node[1];
    int v;
    int lo;

    *(signed char *)(*state + 0x1c6) = 1;
    *(signed char *)(*state + 0x1c7) = -1;
    lo = *(int *)(*state + 0x224);
    v = *(int *)(*state + 0x228) - lo;
    if (v < 0) {
        v = -v;
    }
    state[0x14] = lo + RandNextScaled(v + 1);
    state[3] = *state + 0xb0;
    SetIndexedSlot(node, 0, Ov256_AiDispatchAction);
    SetIndexedSlot(node, 1, Ov256_EnterState);
    SetIndexedSlot(node, 2, Ov256_Update);
}
