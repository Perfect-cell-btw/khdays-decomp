/* Invokes slot 0x74 on the part object (+0x3ac), then the base handler. */

#include "game/enemy_common.h"

extern int Ov107_Actor_DetachFromRegion();

int Ov175_NotifyPartThenBase(int *r0, int r1) {
    Ov107_InvokeSlot0x74(r1, r0[0xeb]);
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
