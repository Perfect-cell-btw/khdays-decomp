/* Releases the table slot and frees the sub-object channels. */

#include "game/engine.h"

extern void *data_ov054_020b74a0;
extern void Ov054_freeSubObjectChannels(char *a);

void Ov054_ReleaseSlotAndChannels(char *a) {
    ReleaseField74AndCleanup((char *)data_ov054_020b74a0 + 0x2cb8);
    Ov054_freeSubObjectChannels(a);
}
