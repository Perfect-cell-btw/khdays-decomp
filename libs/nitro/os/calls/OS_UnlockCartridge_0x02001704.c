/* NitroSDK os (os_spinLock.c): OS_UnlockCartridge -- unlocks the cartridge lock word, freeing the bus. The address suffix is only there because a flat OS_UnlockCartridge.o would be the same file as the OS_UnLockCartridge.o alias on a case-insensitive file system. */
extern void *OSi_DoUnlockByWord();
extern void OSi_FreeCartridgeBus(void);

void *OS_UnlockCartridge_0x02001704(int id) {
    return OSi_DoUnlockByWord(id, (void *)0x27fffe8, OSi_FreeCartridgeBus, 1);
}
