/* Ov008_MissionMenu_OnBack -- close the active mission-info popup, ov008.
 * If the record is modal-but-unconfirmed (rec+0x150 set, rec+0x154 clear) or has no popup open
 * (rec+0x180 == 0), does nothing. Otherwise dismisses (Ov008_ApplyModeWidgets2 when rec+0x184 set),
 * releases (Ov008_ShowMissionInfoPanel) and commits the input latch. */

#include "game/engine.h"

extern int  Ov008_GetPageB(void);
extern void Ov008_ApplyModeWidgets2(int rec, int a);
extern void Ov008_ShowMissionInfoPanel(int rec, int a);

void Ov008_MissionMenu_OnBack(void) {
    int rec = Ov008_GetPageB();
    if (*(int *)(rec + 0x150) != 0 && *(int *)(rec + 0x154) == 0) {
        return;
    }
    if (*(int *)(rec + 0x180) == 0) {
        return;
    }
    if (*(int *)(rec + 0x184) != 0) {
        Ov008_ApplyModeWidgets2(rec, 0);
    }
    Ov008_ShowMissionInfoPanel(rec, 0);
    PlaySound(0, 3);
}
