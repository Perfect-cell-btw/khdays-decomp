/* Frees the object's message block (+0x1b4). */

#include "game/engine.h"

void Ov008_FreeMsgBlock(char *arg0)
{
    ZeroHalfThenFree(*(void **)(arg0 + 0x1b4));
}
