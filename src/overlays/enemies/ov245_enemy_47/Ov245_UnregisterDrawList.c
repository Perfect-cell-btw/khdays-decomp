/* Ov245_UnregisterDrawList -- draw list removal: unregisters the actor's nine +0x3fc parts, the
 * three +0x420 parts, the four +0x42c..+0x438 singles and the three +0x43c parts (020c2b20),
 * telling each of the latter's +0x1ec / +0x1f0 hooks 1 and 2, then the base removal (020c7b70). */

#include "game/enemy_common.h"

struct Ov245Actor {
    char pad[0x3fc];
    int parts[9];
    int arms[3];
    int single42c;
    int single430;
    int single434;
    int single438;
    int tails[3];
};

extern void Ov107_HandleRegionEvent(struct Ov245Actor *self, int list);

void Ov245_UnregisterDrawList(struct Ov245Actor *self, int list) {
    int i;

    for (i = 0; i < 9; i++) {
        Ov107_InitObjectFromSource(list, self->parts[i]);
    }
    for (i = 0; i < 3; i++) {
        Ov107_InitObjectFromSource(list, self->arms[i]);
    }
    Ov107_InitObjectFromSource(list, self->single42c);
    Ov107_InitObjectFromSource(list, self->single430);
    Ov107_InitObjectFromSource(list, self->single434);
    Ov107_InitObjectFromSource(list, self->single438);
    for (i = 0; i < 3; i++) {
        Ov107_InitObjectFromSource(list, self->tails[i]);
        if (*(void (**)(int, int))(self->tails[i] + 0x1ec) != 0) {
            (*(void (**)(int, int))(self->tails[i] + 0x1ec))(self->tails[i], 1);
        }
        if (*(void (**)(int, int))(self->tails[i] + 0x1f0) != 0) {
            (*(void (**)(int, int))(self->tails[i] + 0x1f0))(self->tails[i], 2);
        }
    }
    Ov107_HandleRegionEvent(self, list);
}
