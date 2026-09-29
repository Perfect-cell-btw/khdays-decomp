/* Refreshes the child selector (+0x3a0), then runs the shared object tick. */

#include "game/enemy_common.h"

extern int Ov107_ProcessObjectTick();

int Ov122_ReleaseAndDestroy(int *r0, int r1) {
    Ov107_RefreshAndSelectChild(r0[0xe8], r1);
    return Ov107_ProcessObjectTick(r0, r1);
}
