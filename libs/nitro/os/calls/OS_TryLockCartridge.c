/* NitroSDK os (os_spinLock.c): OS_TryLockCartridge -- tries the cartridge lock word, allocating the bus. */
extern void *OSi_DoTryLockByWord();
extern void OSi_AllocateCartridgeBus(void);

void *OS_TryLockCartridge(int id) {
    return OSi_DoTryLockByWord(id, (void *)0x27fffe8, OSi_AllocateCartridgeBus, 1);
}
