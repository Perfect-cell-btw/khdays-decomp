/* AI step: rolls a random spawn delay within the actor's range and continues with the spawn timer.
 */

#include "game/engine.h"

extern void SetIndexedSlot();
extern void Ov299_SpawnTimerTick();

void Ov299_SetRandomFieldFromScaled390(int this_) {
    int node = *(int *)(this_ + 4);
    int x = *(int *)(*(int *)node + 0x390);
    int v;
    if (x <= 0) v = 0;
    else v = RandNextScaled(x);
    *(int *)(node + 8) = v;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov299_SpawnTimerTick);
}
