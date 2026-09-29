/* Releases both table slots (+0x2c30 and +0x2d4c). */

#include "game/engine.h"

extern void *data_ov076_020b9d00;

void Ov076_ReleaseBothSlots(void) {
    char *base = (char *)data_ov076_020b9d00 + 0x2c2c;
    ReleaseField74AndCleanup(base + 4);
    ReleaseField74AndCleanup(base + 0x120);
}
