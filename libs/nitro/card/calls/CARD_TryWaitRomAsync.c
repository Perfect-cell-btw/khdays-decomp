/* NitroSDK card (card_rom.c): CARD_TryWaitRomAsync -- CARDi_TryWaitAsync(). */
extern void *CARDi_TryWaitAsync();

void *CARD_TryWaitRomAsync() {
    return CARDi_TryWaitAsync();
}
