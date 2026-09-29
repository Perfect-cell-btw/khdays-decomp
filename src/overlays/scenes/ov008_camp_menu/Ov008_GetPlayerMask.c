/* 1 in the local mode, otherwise the packed mask of connected players. */

#include "game/engine.h"

extern int Ov008_Link_IsLocal(void);
int Ov008_GetPlayerMask(void)
{
    if (Ov008_Link_IsLocal() != 0) {
        return 1;
    }
    return Session_PackConnectedPlayerMask();
}
