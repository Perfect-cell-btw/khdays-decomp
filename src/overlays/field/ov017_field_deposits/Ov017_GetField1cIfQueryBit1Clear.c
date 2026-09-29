/* Returns the record's data (+0x1c) unless the game-state flag it names has bit 1 set. */

#include "game/engine.h"

void *Ov017_GetField1cIfQueryBit1Clear(int this_) {
    unsigned int r = GameState_GetField(*(unsigned short *)(this_ + 0x14),
                                   *(unsigned char *)(this_ + 0x16));
    r = ((r & 0xfffe) << 0xf) >> 0x10;
    if (r & 1) return 0;
    return (void *)(this_ + 0x1c);
}
