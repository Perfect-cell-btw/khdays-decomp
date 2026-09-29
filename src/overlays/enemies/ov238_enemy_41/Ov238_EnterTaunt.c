/* Enter the taunt: unless a queued cancel is pending (node[0xd], which it consumes), cancel the
 * current action (mode 0xe), play the taunt sub-animation (Ov107_StartAnim on *node+0x3e0),
 * and seed a random taunt duration (3 + d1) at +0x2d; then register the think callback. */

#include "game/enemy_common.h"

extern int RandNextScaled();
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov238_AiWalkStep(void);

void Ov238_EnterTaunt(int param_1) {
    int *node = *(int **)(param_1 + 4);
    if (node[0xd] == 0) {
        Ov107_PostTagUpdate((Actor *)(*node), 0xe, 0);
        Ov107_StartAnim(*(int *)(*node + 0x3e0), 4, 0);
        *(char *)((char *)node + 0x2d) = RandNextScaled(2) + 3;
    } else {
        node[0xd] = 0;
    }
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov238_AiWalkStep);
}
