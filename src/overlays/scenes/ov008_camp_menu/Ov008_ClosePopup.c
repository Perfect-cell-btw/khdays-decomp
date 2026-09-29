/* Ov008_ClosePopup -- close the active menu popup, ov008.
 * On the active record: if it is modal-but-unconfirmed (rec+0x40 set, rec+0x44 clear) or has
 * no popup open (rec+0x4f8 == 0), does nothing. Otherwise dismisses the popup (Ov008_ApplyModeWidgets
 * when rec+0x4fc set), releases it (Ov008_ShowMissionListInfoPanel) and commits the input latch. */

#include "game/engine.h"

extern int  Ov008_GetPageB(void);
extern void Ov008_ApplyModeWidgets(int rec, int a);
extern void Ov008_ShowMissionListInfoPanel(int rec, int a);

void Ov008_ClosePopup(void) {
    int rec = Ov008_GetPageB();
    if (*(int *)(rec + 0x40) != 0 && *(int *)(rec + 0x44) == 0) {
        return;
    }
    if (*(int *)(rec + 0x4f8) == 0) {
        return;
    }
    if (*(int *)(rec + 0x4fc) != 0) {
        Ov008_ApplyModeWidgets(rec, 0);
    }
    Ov008_ShowMissionListInfoPanel(rec, 0);
    PlaySound(0, 3);
}
