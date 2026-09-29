/* Returns a player's heading (0 when it has no actor). */

#include "game/engine.h"

unsigned short func_ov022_02088254(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    if (e != 0) return *(unsigned short *)(*(int *)(e + 0x20) + 0x80) - 0x8000;
    return 0;
}
