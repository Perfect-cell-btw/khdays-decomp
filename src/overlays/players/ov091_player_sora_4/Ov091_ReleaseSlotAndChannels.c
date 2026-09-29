/* Releases the table slot and frees the sub-object channels. */

#include "game/engine.h"

extern void *data_ov091_020bc240;
extern void Ov091_freeSubObjectChannels(char *a);

void Ov091_ReleaseSlotAndChannels(char *a) {
    ReleaseField74AndCleanup((char *)data_ov091_020bc240 + 0x2cb8);
    Ov091_freeSubObjectChannels(a);
}
