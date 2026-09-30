/* React to a tap on a two-state UI element: in state 0, if the phase byte's 0xe0 bits are clear
 * and the element is not already variant 2, switch it to variant 2 and chirp; in state 1, if the
 * pending flag (+0x64) is set, clear it and chirp. */

#include "game/engine.h"

extern void Ov008_PlaceElementByVariant(int *obj, int variant, int state);
extern unsigned short gPadHeld;

void Ov008_HandleElementTap(int *param_1) {
    int variant = *param_1;
    if (param_1[0x8f] != 0) {
        return;
    }
    switch (param_1[1]) {
    case 0:
        if (gPadHeld & 0xe0) {
            return;
        }
        if (variant == 2) {
            return;
        }
        *param_1 = 2;
        Ov008_PlaceElementByVariant(param_1, variant, 2);
        PlaySound(0, 0);
        break;
    case 1:
        if (param_1[0x19] == 0) {
            return;
        }
        param_1[0x19] = 0;
        PlaySound(0, 0);
        break;
    }
}
