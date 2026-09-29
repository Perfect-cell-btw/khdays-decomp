/* Unlinks the held node (+0x390) from its owner and clears it. */

#include "game/enemy_common.h"

void Ov185_UnlinkHeldNode(int *r0) {
    Ov107_UnlinkNodeFromOwner((void *)r0[0xe4]);
    r0[0xe4] = 0;
}
