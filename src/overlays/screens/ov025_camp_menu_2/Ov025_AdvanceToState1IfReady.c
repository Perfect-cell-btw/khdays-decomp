/* Shows a grid page when the menu has at least two entries and is idle. */

extern int Ov025_GetPageA();
extern void Ov025_ShowGridPage();

void Ov025_AdvanceToState1IfReady(void) {
    int x = Ov025_GetPageA();
    if (*(int *)(x + 0x1e78) < 2) return;
    if (*(int *)(x + 0x30) != 0) return;
    if (*(int *)(x + 0x18) == 1) return;
    Ov025_ShowGridPage(x, 1, 1);
}
