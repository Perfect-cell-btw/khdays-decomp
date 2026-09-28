/* Raises the selected item widget, refreshes the list and redraws the page texts. */

extern int Ov025_RaiseSelectedItemWidget();
extern int Ov025_RegisterSlotCells();
extern int Ov025_DrawMenuPageTexts();

void Ov025_RefreshMenuPage(int arg0) {
    Ov025_RaiseSelectedItemWidget(arg0);
    Ov025_RegisterSlotCells();
    Ov025_DrawMenuPageTexts();
}
