/* Opens the hub sub-menu and plays the confirm sound. */

#include "game/engine.h"

extern int Ov025_GetPageA();
extern int Ov025_Hub_SetSubMenu();

void Ov025_Hub_OpenSubMenu(int arg0) {
    Ov025_Hub_SetSubMenu(Ov025_GetPageA(arg0), 1);
    PlaySound(0, 1);
}
