/* Targets page 5 and plays the confirm sound. */

extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_GoToPage5(void) {
    Ov025_SetTargetSlot(5, -1);
    PlaySound(0, 1);
}
