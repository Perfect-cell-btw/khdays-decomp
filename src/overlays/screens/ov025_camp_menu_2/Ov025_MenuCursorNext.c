/* Plays the cursor sound and moves the menu cursor to the next entry. */

#include "game/engine.h"

extern int Ov025_GetPageA();
extern int Ov025_MoveMenuCursor();

void Ov025_MenuCursorNext(int arg0) {
    short *x = (short *)Ov025_GetPageA(arg0);
    PlaySound(0, 2);
    Ov025_MoveMenuCursor((short)(*x + 1));
}
