/* Ov024_MobiClip_RestoreDisplay -- MobiClip player: restore the fades to a known state and re-arm the
 * display. Any fade level other than the two extremes (+/-0x10) is forced to -0x10 on both
 * screens; then the display is brought back up and POWCNT1 bit 15 (LCD enable) set. */
extern int  func_0201e428(void);
extern void SetMasterBrightnessMain(int level);
extern int  func_0201e438(void);
extern void SetMasterBrightnessSub(int level);
extern void Gfx_Reset2DEngines(void);
extern void Ov024_RunDisplayTeardownSteps(int a, int b);

void Ov024_MobiClip_RestoreDisplay(void) {
    int dark = -0x10;
    int level;

    level = func_0201e428();
    if (level != dark && level != 0x10) {
        level = dark;
    }
    SetMasterBrightnessMain(level);

    level = func_0201e438();
    if (level != dark && level != 0x10) {
        level = dark;
    }
    SetMasterBrightnessSub(level);

    Gfx_Reset2DEngines();
    Ov024_RunDisplayTeardownSteps(1, 1);
    *(volatile unsigned short *)0x04000304 = *(volatile unsigned short *)0x04000304 | 0x8000;
}
