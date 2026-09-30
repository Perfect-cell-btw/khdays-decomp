/* Applies the selection, plays the confirm sound and targets slot 0. */

#include "game/engine.h"

extern void Ov008_GetMenuContext(void);
extern void Ov008_Config_SaveValues(void);
extern void Ov008_SetTargetSlot(int, int);
void Ov008_PageA_ConfirmAndLeave(void)
{
    int mode = 0;
    Ov008_GetMenuContext();
    Ov008_Config_SaveValues();
    PlaySound(0, 1);
    Ov008_SetTargetSlot(mode, mode - 1);
}
