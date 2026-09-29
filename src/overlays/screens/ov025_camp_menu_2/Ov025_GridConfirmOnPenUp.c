/* Ov025_GridConfirmOnPenUp -- confirm the current grid selection on pen-up.
 * Only when the pen is released (touch[2]==0) and the grid is idle (obj+0x30==0), a selection
 * exists (obj+0x4c) and nothing is animating (obj+8): applies obj+0x70 and fires UI event 2. */

#include "game/engine.h"

extern void Ov025_CopySourceBlock(unsigned short *touch);
extern void Ov025_AdvanceIndexBackwardUntilOk(int obj, int key);

void Ov025_GridConfirmOnPenUp(int param_1) {
    unsigned short touch[4];
    Ov025_CopySourceBlock(touch);
    if (touch[2] != 0 || *(int *)(param_1 + 0x30) != 0) {
        return;
    }
    if (*(int *)(param_1 + 0x4c) == 0) {
        return;
    }
    if (*(int *)(param_1 + 8) != 0) {
        return;
    }
    Ov025_AdvanceIndexBackwardUntilOk(param_1, *(int *)(param_1 + 0x70));
    PlaySound(0, 2);
}
