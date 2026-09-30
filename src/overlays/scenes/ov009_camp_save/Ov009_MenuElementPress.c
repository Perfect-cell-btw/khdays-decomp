
#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov009SaveContext {
    int variant;
    u8 pad_004[0x8 - 0x4];
    int state;
    u8 pad_00c[0x68 - 0x0c];
    int pending;
    u8 pad_06c[0x240 - 0x06c];
    int blocked;
} Ov009SaveContext;

extern void Ov009_PlaceElementByVariant(Ov009SaveContext *element, int oldVariant,
                                int newVariant);
extern u16 gPadHeld;

/* Commit the pressed form of a two-state menu element. State 0 changes the
 * visible variant to 2 when no directional input is held; states 1 and 6
 * clear the pending flag. Both paths acknowledge the input latch. */
void Ov009_MenuElementPress(Ov009SaveContext *element)
{
    int variant = element->variant;

    if (element->blocked != 0) {
        return;
    }

    switch (element->state) {
    case 0:
        if (gPadHeld & 0xe0) {
            return;
        }
        if (variant == 2) {
            return;
        }
        element->variant = 2;
        Ov009_PlaceElementByVariant(element, variant, 2);
        PlaySound(0, 0);
        break;

    case 1:
    case 6:
        if (element->pending == 0) {
            return;
        }
        element->pending = 0;
        PlaySound(0, 0);
        break;
    }
}
