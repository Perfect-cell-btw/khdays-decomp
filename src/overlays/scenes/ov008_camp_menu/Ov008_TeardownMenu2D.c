/* Ov008_TeardownMenu2D -- tear down the menu's 2D display, ov008.
 * Releases the menu's object/graphics engine binding (Ov008_PageTeardown), restores the
 * two capture/blend engines (SetMasterBrightnessMain/3cc with -0x10), clears the BG-mode/screen-base
 * bits of both DISPCNT registers, and re-enables the LCD via POWCNT1. Returns 0. */
typedef volatile unsigned int   vu32;
typedef volatile unsigned short vu16;
extern void Ov008_PageTeardown(int a);
extern void SetMasterBrightnessMain(int a);
extern void SetMasterBrightnessSub(int a);

int Ov008_TeardownMenu2D(void) {
    Ov008_PageTeardown(0);
    SetMasterBrightnessMain(-0x10);
    SetMasterBrightnessSub(-0x10);
    *(vu32 *)0x04000000 &= ~0x1f00;
    *(vu32 *)0x04001000 &= ~0x1f00;
    *(vu16 *)0x04000304 |= 0x8000;
    return 0;
}
