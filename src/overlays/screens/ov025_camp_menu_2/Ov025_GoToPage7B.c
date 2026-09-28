/* Selects variant 1, targets page 7 and plays the confirm sound. */

extern int Ov025_SetCtxField9768();
extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_GoToPage7B(void) {
    Ov025_SetCtxField9768(1);
    Ov025_SetTargetSlot(7, -1);
    PlaySound(0, 1);
}
