/* Closes the hub sub-menu and plays the cancel sound. */

extern int Ov025_GetPageA();
extern int Ov025_Hub_SetSubMenu();
extern int PlaySound();

void Ov025_Hub_CloseSubMenu(int arg0) {
    Ov025_Hub_SetSubMenu(Ov025_GetPageA(arg0), 0);
    PlaySound(0, 3);
}
