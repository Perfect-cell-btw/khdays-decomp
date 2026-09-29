/* Plays the cursor sound and moves the menu cursor to the next entry. */

#include "game/engine.h"

extern char *Ov008_GetMenuContext(void);
extern void Ov008_MoveMenuCursor(int arg0);

void Ov008_MenuCursorNext(void)
{
    char *context = Ov008_GetMenuContext();

    PlaySound(0, 2);
    Ov008_MoveMenuCursor((short)(*(short *)context + 1));
}
