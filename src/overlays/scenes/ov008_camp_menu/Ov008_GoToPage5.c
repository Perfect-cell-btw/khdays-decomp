/* Targets page 5 and plays the confirm sound. */

#include "game/engine.h"

extern void Ov008_SetTargetSlot(int, int);
void Ov008_GoToPage5(void)
{
    int mode = 5;
    Ov008_SetTargetSlot(mode, mode - 6);
    PlaySound(0, 1);
}
