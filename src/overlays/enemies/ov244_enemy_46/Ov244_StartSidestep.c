/* Start a sidestep: cancel the current action (mode 1) and roll a random sidestep direction
 * (-1 or +1) into the facing byte at +0x48, then register the sidestep think callback. */

#include "game/enemy_common.h"

extern int RandNextScaled();
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov244_CircleDecision(void);

void Ov244_StartSidestep(int param_1) {
    int v;
    int *node = *(int **)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*node), 1, 1);
    *(char *)((char *)node + 0x48) = RandNextScaled(2) + (v - v) != 0 ? -1 : 1;
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov244_CircleDecision);
}
