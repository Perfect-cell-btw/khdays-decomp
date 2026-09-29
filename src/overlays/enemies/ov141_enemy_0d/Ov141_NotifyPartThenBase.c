/* Invokes slot 0x74 on the part object (+0x3c8), then the base handler. */

#include "game/enemy_common.h"

extern void Ov107_Actor_DetachFromRegion(void *a, void *b);

void Ov141_NotifyPartThenBase(char *a, void *b) {
    Ov107_InvokeSlot0x74((int)b, *(int *)(a + 0x3c8));
    Ov107_Actor_DetachFromRegion(a, b);
}
