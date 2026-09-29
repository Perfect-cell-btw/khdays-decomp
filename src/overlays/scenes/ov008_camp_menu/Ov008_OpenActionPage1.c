/* Unless busy builds action page 1 and plays the confirm sound. */

#include "game/engine.h"

extern char *Ov008_GetMenuContext(void);
extern void Ov008_BuildActionPage(void *context, int arg1);

void Ov008_OpenActionPage1(void)
{
    char *context = Ov008_GetMenuContext();

    if (*(int *)(context + 0x30) == 0) {
        Ov008_BuildActionPage(context, 1);
        PlaySound(0, 1);
    }
}
