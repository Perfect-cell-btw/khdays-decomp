extern int Ov025_SetCtxField9768();
extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_GoToPage7A(void) {
    Ov025_SetCtxField9768(0);
    Ov025_SetTargetSlot(7, -1);
    PlaySound(0, 1);
}
