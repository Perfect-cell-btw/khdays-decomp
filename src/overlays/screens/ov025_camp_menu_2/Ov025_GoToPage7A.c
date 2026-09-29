/* Selects variant 0, targets page 7 and plays the confirm sound. */

#include "game/engine.h"

extern int Ov025_SetCtxField9768();
extern int Ov025_SetTargetSlot();

void Ov025_GoToPage7A(void) {
    Ov025_SetCtxField9768(0);
    Ov025_SetTargetSlot(7, -1);
    PlaySound(0, 1);
}
