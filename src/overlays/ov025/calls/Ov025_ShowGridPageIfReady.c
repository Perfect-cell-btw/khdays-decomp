extern int Ov025_GetPageA();
extern int Ov025_ShowGridPage();

void Ov025_ShowGridPageIfReady(int arg0) {
    int x = Ov025_GetPageA(arg0);
    if (*(int *)(x + 0x30) != 0) {
        return;
    }
    if (*(int *)(x + 0x18) == 0) {
        return;
    }
    Ov025_ShowGridPage(x, 0, 1);
}
