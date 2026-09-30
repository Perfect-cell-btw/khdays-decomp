/* Invokes slot 0x74 on each of the four part objects (+0x3ec), then the base handler. */

#include "game/enemy_common.h"

extern int Ov107_Actor_DetachFromRegion();

void Ov223_NotifyPartsThenBase(int *a, int b)
{
    int i;
    for (i = 0; i < 4; i++) {
        int v = a[i + 0xfb];
        if (v)
            Ov107_InvokeSlot0x74(b, v);
    }
    Ov107_Actor_DetachFromRegion(a, b);
}
