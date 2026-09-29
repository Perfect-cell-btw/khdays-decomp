/* AI step: once the gate byte is clear, posts a pose, clears the timer and installs the wait step.
 */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov139_AiWaitThenAnim11();

void Ov139_GuardField50Pose10ClearAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x50)) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)n), 0xa, 1);
    *(int *)(n + 0x3c) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov139_AiWaitThenAnim11);
}
