/* Returns the address of a player's position, or a default vector when the player has no actor. */

#include "game/engine.h"

extern int data_02041dc8;
int func_ov022_020881f8(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    if (e == 0) return (int)&data_02041dc8;
    return e + 0x48c;
}
