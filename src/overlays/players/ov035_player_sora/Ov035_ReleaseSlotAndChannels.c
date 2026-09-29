/* Releases the table slot and frees the sub-object channels. */

#include "game/engine.h"

extern void *data_ov035_020b4ca0;
extern void Ov035_freeSubObjectChannels(char *a);

void Ov035_ReleaseSlotAndChannels(char *a) {
    ReleaseField74AndCleanup((char *)data_ov035_020b4ca0 + 0x2cb8);
    Ov035_freeSubObjectChannels(a);
}
