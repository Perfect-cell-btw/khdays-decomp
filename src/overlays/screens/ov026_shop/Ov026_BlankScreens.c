/* Ov026_BlankScreens -- restore the capture/blend engines (SetMasterBrightnessMain/3cc with -0x10),
 * clear the BG-mode/screen-base bits of both DISPCNT registers, and switch the main engine
 * to the top physical LCD via Ov002_SetDisplaySwap. */
#include "nitro/types.h"

extern void SetMasterBrightnessMain(int a);
extern void SetMasterBrightnessSub(int a);
extern void Ov002_SetDisplaySwap(int top);

void Ov026_BlankScreens(void) {
    SetMasterBrightnessMain(-0x10);
    SetMasterBrightnessSub(-0x10);
    *(vu32 *)0x04000000 &= ~0x1f00;
    *(vu32 *)0x04001000 &= ~0x1f00;
    Ov002_SetDisplaySwap(1);
}
