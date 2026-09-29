/* Toggles the detail panel and plays the confirm sound. */

#include "game/engine.h"

extern void Ov008_Menu_ToggleDetailPanel(int);
void Ov008_ToggleDetailPanelWithSound(void)
{
    Ov008_Menu_ToggleDetailPanel(1);
    PlaySound(0, 1);
}
