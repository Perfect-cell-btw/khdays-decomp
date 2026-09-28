#include "game/ov008_camp_menu.h"
/* Ov008_GetMissionMenuSelection -- read the confirmed menu selection.
 * While idle (base+0x4e8 == 0) returns the live cursor selection
 * (func_ov105_020bf240); once locked in it returns -1.
 *
 * PROVENANCE: byte-identical twin of Ov006_GetMissionMenuSelection, propagated from it. The "Mission Mode"
 * framing in that rep is ov006's own scene identity -- ov008 loads the same UI/mlt/* resources,
 * so it is plausible here, but it has not been verified for THIS function. Not asserted. */
extern int func_ov105_020bf240(void);
#define MISSION_CONTEXT ((int)data_ov008_02090f24.pContext)

int Ov008_GetMissionMenuSelection(void) {
    int sel;
    if (*(int *)(MISSION_CONTEXT + 0x4e8) != 0) {
        sel = -1;
    } else {
        sel = func_ov105_020bf240();
    }
    return (char)sel;
}
