extern int Ov025_GetPageB();
extern int Ov025_ChangeMenuSelection();
extern int PlaySound();

void Ov025_PageB_SelectNext(int arg0) {
    int x = Ov025_GetPageB(arg0);
    if (*(int *)(x + 8) != 0) {
        return;
    }
    Ov025_ChangeMenuSelection(x, 1, 0x64);
    PlaySound(0, 2);
}
