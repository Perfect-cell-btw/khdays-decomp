/* Returns the local player's index when the battle session is networked, otherwise whether the
 * single-player battle is active. */

#include "game/engine.h"

extern int data_ov022_020b2e78[];
extern unsigned char data_0204be04;
int QueryActiveStateOrDelegate(void)
{
    unsigned int *p = *(unsigned int **)((char *)data_ov022_020b2e78 + 4);
    if (p == 0)
        return 0;
    if ((*p & 2) == 0) {
        if (data_0204be04 != 0 && p[4] != 0)
            return 1;
        return 0;
    }
    return Session_GetLocalPlayerIndex();
}
