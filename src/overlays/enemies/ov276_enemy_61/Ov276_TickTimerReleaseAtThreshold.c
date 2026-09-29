#include "game/enemy_common.h"

extern void Ov276_startAnim(int obj, int a);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov276_AiTurnTick(void);

// Accumulate the per-frame step (this[0]+0x2c) into the node timer (node[0x4c]).
// Once it reaches 0x666, reset the object to mode 0, run the release handler,
// clear the timer and advance the sub-state with the follow-up callback.
void Ov276_TickTimerReleaseAtThreshold(int *this)
{
    int obj = this[0];
    int node = this[1];
    int acc = *(int *)(node + 0x4c) + *(int *)(obj + 0x2c);
    *(int *)(node + 0x4c) = acc;
    if (acc < 0x666) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*(int *)node), 0, 0);
    Ov276_startAnim(*(int *)node, 0);
    *(int *)(node + 0x4c) = 0;
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov276_AiTurnTick);
}
