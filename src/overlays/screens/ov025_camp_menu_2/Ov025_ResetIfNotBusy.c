/* When page B is free, clears the target slot and the selection flags with a sound. */

extern int Ov025_GetPageA();
extern int Ov025_PageB_IsBusyOrInactive();
extern void PlaySound();
extern void Ov025_SetTargetSlot();

void Ov025_ResetIfNotBusy(void) {
    int x = Ov025_GetPageA();
    if (Ov025_PageB_IsBusyOrInactive() != 0) return;
    PlaySound(0, 3);
    Ov025_SetTargetSlot(0, -1);
    *(unsigned int *)(x + 0xc) &= 0xffffff0f;
}
