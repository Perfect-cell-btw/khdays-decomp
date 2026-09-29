/* Ov008_RequestMode7 -- if the menu's "busy/locked" flag (bit 5 of *(u16*)(obj+0x5c6)) is set,
 * kick a state transition: set mode 7 (Ov008_PrimeSubSceneFromCursor), clear the active slot
 * (Ov008_SetTargetSlot(-1,-1)) and fire a UI event (PlaySound(0,1)). ov008. One of a
 * 5-member family (02059a54/b14/b5c/ba4/bec) differing in the transition constants. */

#include "game/engine.h"

extern int  Ov008_PrimeSubSceneFromCursor(int mode);
extern void Ov008_SetTargetSlot(int a, int b);
extern char *data_ov008_02090f1c;   /* -> menu/status object */

void Ov008_RequestMode7(void) {
    if ((((unsigned)*(unsigned short *)(data_ov008_02090f1c + 0x5c6) << 0x1a) >> 0x1f) == 0) {
        return;
    }
    Ov008_PrimeSubSceneFromCursor(7);
    Ov008_SetTargetSlot(-1, -1);
    PlaySound(0, 1);
}
