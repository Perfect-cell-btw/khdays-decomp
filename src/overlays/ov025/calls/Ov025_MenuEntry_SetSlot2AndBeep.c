extern int Ov025_SetTargetSlot();
extern int PlaySound();

void Ov025_MenuEntry_SetSlot2AndBeep(void) {
    Ov025_SetTargetSlot(2, -1);
    PlaySound(0, 1);
}
