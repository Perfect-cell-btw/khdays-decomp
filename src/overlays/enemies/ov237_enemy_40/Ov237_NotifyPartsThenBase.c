/* Forward the sub-object at (obj)+0x3e0, and (if present) the one at +0x4a4, to the ov107
 * callback dispatcher, then tail-call the base ov107 handler for the pair. */

#include "game/enemy_common.h"

extern void Ov107_Actor_DetachFromRegion(int obj, int arg1);

void Ov237_NotifyPartsThenBase(int param_1, int param_2) {
    Ov107_InvokeSlot0x74(param_2, *(int *)(param_1 + 0x3e0));

    int field_4a4 = *(int *)(param_1 + 0x4a4);
    if (field_4a4 != 0) {
        Ov107_InvokeSlot0x74(param_2, field_4a4);
    }

    Ov107_Actor_DetachFromRegion(param_1, param_2);
}
