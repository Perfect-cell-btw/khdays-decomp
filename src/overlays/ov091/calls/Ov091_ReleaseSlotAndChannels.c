/* Releases the table slot and frees the sub-object channels. */

extern void *data_ov091_020bc240;
extern void ReleaseField74AndCleanup(void *p);
extern void Ov091_freeSubObjectChannels(char *a);

void Ov091_ReleaseSlotAndChannels(char *a) {
    ReleaseField74AndCleanup((char *)data_ov091_020bc240 + 0x2cb8);
    Ov091_freeSubObjectChannels(a);
}
