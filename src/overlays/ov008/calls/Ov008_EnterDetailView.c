extern char *data_ov008_02090fac;
extern int Ov008_OpenSellDialog(void);
extern void Ov008_DrawTitleBar(int caption);
extern int Ov008_GetVarRecordByIndex(void *p, int id);
extern void Ov008_DrawDescriptionText(int src, int arg);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_Shop_QuantityDialogTick(void);

/* Enters the detail view: picks the title-bar caption from the current tab and blits the entry's
 * description. */
void *Ov008_EnterDetailView(void) {
    int caption;
    int entry = Ov008_OpenSellDialog();
    int tab = *(int *)(*(char **)&data_ov008_02090fac + 0xc250);
    switch (tab) {
    case 0:
        caption = 0xd;
        break;
    case 1:
        caption = 0x10;
        break;
    }
    Ov008_DrawTitleBar(caption);
    Ov008_DrawDescriptionText(Ov008_GetVarRecordByIndex(*(char **)&data_ov008_02090fac + 0xc130, entry), -1);
    Ov008_RefreshPanelDisplay();
    return (void *)&Ov008_Shop_QuantityDialogTick;
}
