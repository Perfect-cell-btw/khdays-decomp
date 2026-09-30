/* Refreshes the child selector at +0x3c8, then runs the object tick. */

#include "game/enemy_common.h"

extern int Ov107_ProcessObjectTick();

int Ov133_TickWithChildRefresh(int *r0, int r1)
{
    Ov107_RefreshAndSelectChild(r0[0xf2], r1);
    return Ov107_ProcessObjectTick(r0, r1);
}
