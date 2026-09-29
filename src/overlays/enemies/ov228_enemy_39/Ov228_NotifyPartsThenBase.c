/* Invokes slot 0x74 on the eight part objects (+0x3c0), then the base handler. */

#include "game/enemy_common.h"

extern int Ov107_Actor_DetachFromRegion();

int Ov228_NotifyPartsThenBase(int *r0, int r1) {
    int i;
    for (i = 0; i < 8; i++) {
        Ov107_InvokeSlot0x74(r1, r0[i + 0xf0]);
    }
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
