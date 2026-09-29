/* Detach hook of the ov254 enemy: unregisters its four effects (+0x468, +0x45c, +0x460, +0x464), the
 * sixteen +0x46c slots and the ten +0x4ac slots from the given list, then runs the base detach
 * (020c7c1c). */

#include "game/enemy_common.h"

extern void Ov107_Actor_DetachFromRegion(char *self, int list);

void Ov254_DetachHook(char *self, int list)
{
    int i;

    Ov107_InvokeSlot0x74(list, *(int *)(self + 0x468));
    Ov107_InvokeSlot0x74(list, *(int *)(self + 0x45c));
    Ov107_InvokeSlot0x74(list, *(int *)(self + 0x460));
    Ov107_InvokeSlot0x74(list, *(int *)(self + 0x464));
    for (i = 0; i < 16; i++) {
        Ov107_InvokeSlot0x74(list, ((int *)(self + 0x46c))[i]);
    }
    for (i = 0; i < 10; i++) {
        Ov107_InvokeSlot0x74(list, ((int *)(self + 0x4ac))[i]);
    }
    Ov107_Actor_DetachFromRegion(self, list);
}
