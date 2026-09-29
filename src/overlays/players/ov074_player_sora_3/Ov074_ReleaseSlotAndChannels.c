/* Releases the table slot and frees the sub-object channels. */

#include "game/engine.h"

extern void *data_ov074_020b9b80;
extern void Ov074_freeSubObjectChannels(char *a);

void Ov074_ReleaseSlotAndChannels(char *a) {
    ReleaseField74AndCleanup((char *)data_ov074_020b9b80 + 0x2cb8);
    Ov074_freeSubObjectChannels(a);
}
