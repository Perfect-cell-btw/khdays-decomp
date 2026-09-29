/* Returns the local player's index in the session. */

#include "game/engine.h"

int Ov008_GetLocalPlayerIndex(void)
{
    return (unsigned short)Session_GetLocalPlayerIndex();
}
