/* Invokes slot 0x74 on the part object (+0x3a0), then the base handler. */

#include "game/enemy_common.h"

extern int Ov107_Actor_DetachFromRegion();

int Ov138_NotifyPartThenBase(int *r0, int r1) {
    Ov107_InvokeSlot0x74(r1, r0[0x3a0 / 4]);
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
