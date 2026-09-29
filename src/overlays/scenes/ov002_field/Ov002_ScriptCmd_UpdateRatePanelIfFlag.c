/* Script command: updates the rate panel when game flag 0x20e8 is set; returns 1. */

#include "game/engine.h"

extern int Ov002_UpdateRatePanel();

int Ov002_ScriptCmd_UpdateRatePanelIfFlag(void) {
    if (GameState_IsFlagSet(0x20e8) != 0) {
        Ov002_UpdateRatePanel();
    }
    return 1;
}
