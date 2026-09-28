/* Applies the selection, plays the confirm sound and targets slot 0. */

extern int Ov025_GetPageA();
extern int Ov025_Config_SaveValues();
extern int PlaySound();
extern int Ov025_SetTargetSlot();

void Ov025_PageA_ConfirmAndLeave(int arg0) {
    Ov025_GetPageA(arg0);
    Ov025_Config_SaveValues();
    PlaySound(0, 1);
    Ov025_SetTargetSlot(0, -1);
}
