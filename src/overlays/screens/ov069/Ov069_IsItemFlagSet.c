/* Whether the save block's +0x10e0 bit array has bit `id` set (ids from 0x400 up are never set). */

#include "game/engine.h"

extern char *gGameState;

int Ov069_IsItemFlagSet(unsigned int id)
{
    if (id >= 0x400) {
        return 0;
    }
    if (BitArray_TestBit(gGameState + 0x10e0, id) != 0) {
        return 1;
    }
    return 0;
}
