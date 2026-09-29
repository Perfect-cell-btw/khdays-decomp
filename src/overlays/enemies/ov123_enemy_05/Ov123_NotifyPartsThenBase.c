/* Invokes slot 0x74 on the part objects, then the base handler. */

#include "game/enemy_common.h"

extern void Ov107_Actor_DetachFromRegion(void *a, void *b);

void Ov123_NotifyPartsThenBase(char *a, void *b) {
    Ov107_InvokeSlot0x74((int)b, *(int *)(a + 0x394));
    Ov107_Actor_DetachFromRegion(a, b);
}
