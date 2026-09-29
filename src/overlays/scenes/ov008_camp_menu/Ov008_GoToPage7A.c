/* Selects variant 0, targets page 7 and plays the confirm sound. */

#include "game/engine.h"

extern void Ov008_SetCtxField9768(int);
extern void Ov008_SetTargetSlot(int, int);
void Ov008_GoToPage7A(void)
{
    int mode = 7;
    Ov008_SetCtxField9768(0);
    Ov008_SetTargetSlot(mode, mode - 8);
    PlaySound(0, 1);
}
