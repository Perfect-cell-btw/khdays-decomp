/* Closes the mission info panel when it is open, otherwise leaves the menu; plays the cancel sound.
 */

#include "game/engine.h"

extern void Ov025_ShowMissionInfoPanel();
extern void Ov025_SetGlobalConfigAndInit();

void Ov025_TeardownOrInit(int arg0) {
    if (*(int *)(arg0 + 0x180) != 0) {
        *(int *)(arg0 + 0x184) = 0;
        Ov025_ShowMissionInfoPanel(arg0, 0);
        PlaySound(0, 3);
        return;
    }
    Ov025_SetGlobalConfigAndInit(1);
    PlaySound(0, 3);
}
