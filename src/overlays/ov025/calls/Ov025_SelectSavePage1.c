extern int Ov025_GetPageA();
extern int Ov025_SetField20AndDispatch();
extern int Ov025_DrawSavePage();

void Ov025_SelectSavePage1(int arg0) {
    int x = Ov025_GetPageA(arg0);
    if (*(int *)(x + 0x30) != 0) {
        return;
    }
    Ov025_SetField20AndDispatch(x, 1);
    Ov025_DrawSavePage(x, 1);
}
