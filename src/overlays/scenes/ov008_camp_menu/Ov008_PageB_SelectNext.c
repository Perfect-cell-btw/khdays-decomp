/* Unless busy moves the page B selection forward and plays the cursor sound. */

#include "game/engine.h"

extern char *Ov008_GetPageB(void);
extern void Ov008_ChangeMenuSelection(void *context, int arg1, int arg2);

void Ov008_PageB_SelectNext(void)
{
    char *context = Ov008_GetPageB();

    if (*(int *)(context + 8) == 0) {
        Ov008_ChangeMenuSelection(context, 1, 0x64);
        PlaySound(0, 2);
    }
}
