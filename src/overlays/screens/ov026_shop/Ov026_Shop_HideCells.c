/* Ov026_Shop_HideCells -- re-register the mission grid's 14 cell sprites, ov008.
 * Through the shared object manager (base+0xbfb0), re-adds the two header cells (base+0xc57c,
 * base+0xc580) and the 12 mission-slot cells (base+0xc584 + i*4) via Slot_UnlinkIfLinked. */

#include "game/engine.h"

extern int  data_ov026_02091368;

void Ov026_Shop_HideCells(void) {
    int base = data_ov026_02091368;
    int *cells = (int *)(base + 0xc57c);
    int *mgr = *(int **)(base + 0xbfb0);
    int i;
    Slot_UnlinkIfLinked(mgr, cells[0]);
    Slot_UnlinkIfLinked(mgr, cells[1]);
    i = 0;
    do {
        Slot_UnlinkIfLinked(mgr, cells[i + 2]);
        i++;
    } while (i < 0xc);
}
