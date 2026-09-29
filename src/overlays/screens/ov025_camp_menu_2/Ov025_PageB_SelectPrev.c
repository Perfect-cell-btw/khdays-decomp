/* Unless busy moves the page B selection back and plays the cursor sound. */

#include "game/engine.h"

extern int Ov025_GetPageB();
extern int Ov025_ChangeMenuSelection();

void Ov025_PageB_SelectPrev(int arg0) {
    int x = Ov025_GetPageB(arg0);
    if (*(int *)(x + 8) != 0) {
        return;
    }
    Ov025_ChangeMenuSelection(x, 0, 0x64);
    PlaySound(0, 2);
}
