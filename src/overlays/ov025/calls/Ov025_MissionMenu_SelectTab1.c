/* Unless busy switches to tab 1 and plays the tab sound. */

extern int Ov025_GetPageB();
extern int Ov025_SwitchMenuTab();
extern int PlaySound();

void Ov025_MissionMenu_SelectTab1(void) {
    int x = Ov025_GetPageB();
    if (*(int *)(x + 0x180) != 0) {
        return;
    }
    Ov025_SwitchMenuTab(Ov025_GetPageB(), 1);
    PlaySound(0, 0);
}
