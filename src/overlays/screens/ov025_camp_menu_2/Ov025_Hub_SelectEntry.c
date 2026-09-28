/* Stores the selection, clears the target slot and plays the confirm sound. */

extern int Ov025_SetCtxField960c();
extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_Hub_SelectEntry(int arg0) {
    Ov025_SetCtxField960c(arg0);
    Ov025_SetTargetSlot(-1, -1);
    PlaySound(0, 1);
}
