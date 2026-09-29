/* Ov008_RequestMode5 -- if menu busy/lock bit 4 of *(u16*)(obj+0x5c6) is set, return; otherwise
 * kick a state transition: mode 5 (Ov008_PrimeSubSceneFromCursor), slot set (Ov008_SetTargetSlot),
 * UI event (PlaySound(0,1)). ov008. Member of the 02059a54 5-func transition family. */

#include "game/engine.h"

extern int  Ov008_PrimeSubSceneFromCursor(int mode);
extern void Ov008_SetTargetSlot(int a, int b);
extern char *data_ov008_02090f1c;   /* -> menu/status object */

void Ov008_RequestMode5(void) {
    if ((((unsigned)*(unsigned short *)(data_ov008_02090f1c + 0x5c6) << 0x1b) >> 0x1f) != 0) {
        return;
    }
    Ov008_PrimeSubSceneFromCursor(5);
    Ov008_SetTargetSlot(5, -1);
    PlaySound(0, 1);
}
