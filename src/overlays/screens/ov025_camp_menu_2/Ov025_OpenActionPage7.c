/* Unless busy builds action page 7 and plays the confirm sound. */

#include "game/engine.h"

extern int Ov025_GetPageA();
extern int Ov025_BuildActionPage();

void Ov025_OpenActionPage7(int arg0) {
    int x = Ov025_GetPageA(arg0);
    if (*(int *)(x + 0x30) != 0) {
        return;
    }
    Ov025_BuildActionPage(x, 7);
    PlaySound(0, 1);
}
