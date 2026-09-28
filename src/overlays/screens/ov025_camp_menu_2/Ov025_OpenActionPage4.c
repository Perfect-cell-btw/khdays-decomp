/* Unless busy builds action page 4 and plays the confirm sound. */

extern int Ov025_GetPageA();
extern int Ov025_BuildActionPage();
extern int PlaySound();

void Ov025_OpenActionPage4(int arg0) {
    int x = Ov025_GetPageA(arg0);
    if (*(int *)(x + 0x30) != 0) {
        return;
    }
    Ov025_BuildActionPage(x, 4);
    PlaySound(0, 1);
}
