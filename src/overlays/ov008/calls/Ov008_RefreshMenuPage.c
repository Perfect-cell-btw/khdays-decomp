/* Raises the selected item widget, refreshes the list and redraws the page texts. */

extern void Ov008_RaiseSelectedItemWidget(void);
extern void Ov008_RegisterSlotCells(void);
extern void Ov008_DrawMenuPageTexts(void);
void Ov008_RefreshMenuPage(void)
{
    Ov008_RaiseSelectedItemWidget();
    Ov008_RegisterSlotCells();
    Ov008_DrawMenuPageTexts();
}
