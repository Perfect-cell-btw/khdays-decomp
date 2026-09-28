/* Waits for the card ROM transfer (CARD_TryWaitRomAsync). Returns whether the transfer has
 * finished. */

extern void *CARD_TryWaitRomAsync();
void *Ov008_CARD_TryWaitRomAsync()
{
    return CARD_TryWaitRomAsync();
}
