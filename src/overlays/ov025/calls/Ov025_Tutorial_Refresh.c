extern int Ov025_GetPageA();
extern int Ov025_Tutorial_UpdateScrollBar();
extern int Ov025_Tutorial_PlaceMarkers();
extern int Ov025_Tutorial_DrawTitles();
extern int Ov025_ScrollListToRow();

void Ov025_Tutorial_Refresh(int arg0) {
    int x = Ov025_GetPageA(arg0);
    Ov025_Tutorial_UpdateScrollBar();
    Ov025_Tutorial_PlaceMarkers();
    Ov025_Tutorial_DrawTitles();
    Ov025_ScrollListToRow(*(signed short *)x);
}
