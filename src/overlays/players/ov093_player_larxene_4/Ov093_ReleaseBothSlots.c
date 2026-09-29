/* Releases both table slots (+0x2c30 and +0x2d4c). */

#include "game/engine.h"

extern void *data_ov093_020bc3c0;

void Ov093_ReleaseBothSlots(void) {
    char *base = (char *)data_ov093_020bc3c0 + 0x2c2c;
    ReleaseField74AndCleanup(base + 4);
    ReleaseField74AndCleanup(base + 0x120);
}
