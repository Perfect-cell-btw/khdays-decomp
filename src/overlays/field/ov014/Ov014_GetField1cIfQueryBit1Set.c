/* Returns the element's payload address when bit 1 of its game-state field is set, otherwise NULL.
 */

#include "game/engine.h"

void *Ov014_GetField1cIfQueryBit1Set(int this_) {
    unsigned int r = GameState_GetField(*(unsigned short *)(this_ + 0x14),
                                   *(unsigned char *)(this_ + 0x16));
    r = ((r & 0xfffe) << 0xf) >> 0x10;
    if ((r & 1) == 0) return 0;
    return (void *)(this_ + 0x1c);
}
