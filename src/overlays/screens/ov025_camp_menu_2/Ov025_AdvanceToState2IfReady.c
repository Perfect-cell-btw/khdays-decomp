/* Shows a grid page when the menu has at least two entries and is idle. */

extern int Ov025_GetPageA();
extern void Ov025_ShowGridPage();

void Ov025_AdvanceToState2IfReady(void) {
    int x = Ov025_GetPageA();
    if (*(int *)(x + 0x1e78) < 3) return;
    if (*(int *)(x + 0x30) != 0) return;
    if (*(int *)(x + 0x18) == 2) return;
    Ov025_ShowGridPage(x, 2, 1);
}
