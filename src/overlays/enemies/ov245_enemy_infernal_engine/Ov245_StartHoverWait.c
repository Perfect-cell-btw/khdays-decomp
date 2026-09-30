/* Start a hover/wait: cancel the current action (mode 1) and seed a randomised wait timer
 * (0x1000 + d0x4001) into node[0xc], then register the wait think callback. */

#include "game/enemy_common.h"
#include "game/engine.h"

extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov245_WaitForFreeSlot(void);

void Ov245_StartHoverWait(int param_1) {
    int *node = *(int **)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*node), 1, 1);
    node[0xc] = RandNextScaled(0x4001) + 0x1000;
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov245_WaitForFreeSlot);
}
