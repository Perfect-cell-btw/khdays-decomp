/* Ov253_DrawListRegister -- draw list registration: handles the +0x460 single, the four +0x458 parts and the
 * eight +0x45c parts (020c2b38), then the base registration (020c7c1c). */

#include "game/enemy_common.h"

struct Ov253Actor { char pad[0x458]; int *parts4; int *parts8; int single; };

extern void Ov107_Actor_DetachFromRegion(struct Ov253Actor *self, int list);

void Ov253_DrawListRegister(struct Ov253Actor *self, int list) {
    int i;

    Ov107_InvokeSlot0x74(list, self->single);
    for (i = 0; i < 4; i++) {
        Ov107_InvokeSlot0x74(list, self->parts4[i]);
    }
    for (i = 0; i < 8; i++) {
        Ov107_InvokeSlot0x74(list, self->parts8[i]);
    }
    Ov107_Actor_DetachFromRegion(self, list);
}
