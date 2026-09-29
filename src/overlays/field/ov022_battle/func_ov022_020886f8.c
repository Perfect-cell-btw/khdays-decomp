/* Returns a player's flag 0x10000 (0 in mode 0x2a or without an actor). */

#include "game/engine.h"

unsigned int func_ov022_020886f8(int arg0) {
    int p;
    if (LoadGlobalU16At0() == 0x2a) return 0;
    p = GetEntryField20ByIndex(arg0);
    if (p == 0) return 0;
    return *(unsigned int *)p & 0x10000;
}
