/* Targets page 4 and plays the confirm sound. */

#include "game/engine.h"

extern int Ov025_SetTargetSlot();

void Ov025_GoToPage4(void) {
    Ov025_SetTargetSlot(4, -1);
    PlaySound(0, 1);
}
