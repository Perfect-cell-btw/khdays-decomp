/* Unless busy switches to tab 0 and plays the tab sound. */

#include "game/engine.h"

extern int Ov025_GetPageB();
extern int Ov025_SwitchMenuTab();

void Ov025_MissionMenu_SelectTab0(void) {
    int x = Ov025_GetPageB();
    if (*(int *)(x + 0x180) != 0) {
        return;
    }
    Ov025_SwitchMenuTab(Ov025_GetPageB(), 0);
    PlaySound(0, 0);
}
