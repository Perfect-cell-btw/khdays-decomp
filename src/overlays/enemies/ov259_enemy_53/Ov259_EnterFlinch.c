/* Enter the flinch state, but only while the target lock (node[1]+0xad) is clear: advance the RNG
 * once (to desync), set the reaction state to 2, and re-register the think callback. */

#include "game/engine.h"

extern void SetIndexedSlot(int self, int idx, int cb);

void Ov259_EnterFlinch(int param_1) {
    int *node = *(int **)(param_1 + 4);
    if (*(unsigned char *)(node[1] + 0xad) != 0) {
        return;
    }
    RandNextScaled(0x65);
    *(char *)(*node + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), 0);
}
