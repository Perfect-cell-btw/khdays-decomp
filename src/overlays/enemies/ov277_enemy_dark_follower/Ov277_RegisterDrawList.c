/* Draw list registration: registers the two +0x400 parts, the six +0x404 slots and the four
 * +0x408 parts (020c2b38), then the base registration (020c7c1c). */

#include "game/enemy_common.h"

struct Ov244Actor { char pad[0x400]; int *parts2; int *slots6; int *parts4; };

extern void Ov107_Actor_DetachFromRegion(struct Ov244Actor *self, int list);

void Ov277_RegisterDrawList(struct Ov244Actor *self, int list) {
    int i;

    for (i = 0; i < 2; i++) {
        Ov107_InvokeSlot0x74(list, self->parts2[i]);
    }
    for (i = 0; i < 6; i++) {
        Ov107_InvokeSlot0x74(list, self->slots6[i]);
    }
    for (i = 0; i < 4; i++) {
        Ov107_InvokeSlot0x74(list, self->parts4[i]);
    }
    Ov107_Actor_DetachFromRegion(self, list);
}
