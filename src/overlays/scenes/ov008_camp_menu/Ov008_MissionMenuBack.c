/* Ov008_MissionMenuBack -- ov008 mission menu "back". If a selection is pending (obj+0x180), clear
 * its armed flag (obj+0x184), collapse the info panel (Ov008_ShowMissionInfoPanel) and fire UI event 3.
 * Otherwise step back one page (Ov008_SetGlobalConfigAndInit(1)) and fire UI event 3. */

#include "game/engine.h"

extern void Ov008_ShowMissionInfoPanel(int obj, int arg);
extern void Ov008_SetGlobalConfigAndInit(int step);

void Ov008_MissionMenuBack(int param_1) {
    if (*(int *)(param_1 + 0x180) != 0) {
        *(int *)(param_1 + 0x184) = 0;
        Ov008_ShowMissionInfoPanel(param_1, 0);
        PlaySound(0, 3);
        return;
    }
    Ov008_SetGlobalConfigAndInit(1);
    PlaySound(0, 3);
}
