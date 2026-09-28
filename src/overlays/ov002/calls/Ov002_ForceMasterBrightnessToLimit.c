/* Snap the master brightness to a saturated value and push it to both engines.
 * The stored level survives only when it is already fully dark (-16) or fully
 * bright (+16); anything in between is forced to fully dark. Gfx_Reset2DEngines then
 * commits the change. */
extern int func_0201e428(void);
extern void SetMasterBrightnessMain(int ev);
extern void SetMasterBrightnessSub(int ev);
extern void Gfx_Reset2DEngines(void);

void Ov002_ForceMasterBrightnessToLimit(void) {
    int ev = func_0201e428();

    if (ev != -0x10 && ev != 0x10) {
        ev = -0x10;
    }
    SetMasterBrightnessMain(ev);
    SetMasterBrightnessSub(ev);
    Gfx_Reset2DEngines();
}
