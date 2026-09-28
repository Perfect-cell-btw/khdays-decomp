extern int Ov025_GetPageB();
extern int Ov025_DragInfoPanel();

void Ov025_BeginInfoPanelDrag(int arg0) {
    int x = Ov025_GetPageB(arg0);
    if (*(int *)(x + 0x180) != 0) {
        return;
    }
    *(int *)(x + 0x158) = 1;
    Ov025_DragInfoPanel(x);
}
