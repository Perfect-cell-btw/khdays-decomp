/* NitroSDK os (os_spinLock.c): OS_UnlockByWord -- OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, FALSE). */
extern void *OSi_DoUnlockByWord();

void *OS_UnlockByWord(int a, void *b, void *c) {
    return OSi_DoUnlockByWord(a, b, c, 0);
}
