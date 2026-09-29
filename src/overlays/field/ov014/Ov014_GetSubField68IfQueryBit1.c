/* Returns the pool's value (+0x68) when bit 1 of the element's game-state field is set, otherwise
 * NULL. */

#include "game/engine.h"

void *Ov014_GetSubField68IfQueryBit1(int this_) {
    int sub = *(int *)(this_ + 8);
    unsigned int r = GameState_GetField(*(unsigned short *)(this_ + 0x14),
                                   *(unsigned char *)(this_ + 0x16));
    r = ((r & 0xfffe) << 0xf) >> 0x10;
    if ((r & 1) == 0) return 0;
    return *(void **)(sub + 0x68);
}
