/* Stores the selection, clears the target slot and plays the confirm sound. */

#include "game/engine.h"

extern int Ov025_SetCtxField960c();
extern int Ov025_SetTargetSlot();

void Ov025_Hub_SelectEntry(int arg0) {
    Ov025_SetCtxField960c(arg0);
    Ov025_SetTargetSlot(-1, -1);
    PlaySound(0, 1);
}
