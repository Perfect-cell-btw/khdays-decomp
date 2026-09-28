extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_GoToPage4(void) {
    Ov025_SetTargetSlot(4, -1);
    PlaySound(0, 1);
}
