/* Attach hook of the ov254 enemy: registers its four effects (+0x468, +0x45c, +0x460, +0x464), the
 * sixteen +0x46c slots and the ten +0x4ac slots with the given list, then runs the base attach
 * (020c7b70). */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(char *self, int list);

void Ov254_AttachHook(char *self, int list)
{
    int i;

    Ov107_InitObjectFromSource(list, *(int *)(self + 0x468));
    Ov107_InitObjectFromSource(list, *(int *)(self + 0x45c));
    Ov107_InitObjectFromSource(list, *(int *)(self + 0x460));
    Ov107_InitObjectFromSource(list, *(int *)(self + 0x464));
    for (i = 0; i < 16; i++) {
        Ov107_InitObjectFromSource(list, ((int *)(self + 0x46c))[i]);
    }
    for (i = 0; i < 10; i++) {
        Ov107_InitObjectFromSource(list, ((int *)(self + 0x4ac))[i]);
    }
    Ov107_HandleRegionEvent(self, list);
}
