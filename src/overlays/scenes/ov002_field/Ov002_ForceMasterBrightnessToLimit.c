/* Snap the master brightness to a saturated value and push it to both engines.
 * The stored level survives only when it is already fully dark (-16) or fully
 * bright (+16); anything in between is forced to fully dark. Gfx_Reset2DEngines then
 * commits the change. */

#include "game/engine.h"

void Ov002_ForceMasterBrightnessToLimit(void) {
    int ev = GetMasterBrightnessMain();

    if (ev != -0x10 && ev != 0x10) {
        ev = -0x10;
    }
    SetMasterBrightnessMain(ev);
    SetMasterBrightnessSub(ev);
    Gfx_Reset2DEngines();
}
