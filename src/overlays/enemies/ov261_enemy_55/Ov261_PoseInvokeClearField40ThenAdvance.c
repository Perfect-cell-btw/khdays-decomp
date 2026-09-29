/* State step: posts tag 1, sends a state update, clears the timer and installs the dual-timer step.
 */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot();
extern void Ov261_stateDualTimerDivide();

void Ov261_PoseInvokeClearField40ThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)node), 1, 1);
    Ov107_BuildAndSendUpdate(*(int *)node, 0x179, 4, *(int *)(node + 4));
    *(int *)(node + 0x40) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov261_stateDualTimerDivide);
}
