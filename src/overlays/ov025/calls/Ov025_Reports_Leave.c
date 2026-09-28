extern int Ov025_GetPageA();
extern int PlaySound();
extern int Ov025_SetTargetSlot();

void Ov025_Reports_Leave(int arg0) {
    int x = Ov025_GetPageA(arg0);
    PlaySound(0, 3);
    Ov025_SetTargetSlot(0, -1);
    *(int *)(x + 0xc8) = 0;
}
