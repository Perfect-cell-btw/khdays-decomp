extern char *data_ov026_02091368;
extern int Ov026_OpenSellDialog(void);
extern void Ov026_DrawTitleBar(int caption);
extern int Ov026_GetVarRecordByIndex(void *p, int id);
extern void Ov026_DrawDescriptionText(int src, int arg);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_Shop_QuantityDialogTick(void);

/* Enters the detail view: picks the title-bar caption from the current tab and blits the entry's
 * description. */
void *Ov026_EnterDetailView(void) {
    int caption;
    int entry = Ov026_OpenSellDialog();
    int tab = *(int *)(*(char **)&data_ov026_02091368 + 0xc250);
    switch (tab) {
    case 0:
        caption = 0xd;
        break;
    case 1:
        caption = 0x10;
        break;
    }
    Ov026_DrawTitleBar(caption);
    Ov026_DrawDescriptionText(Ov026_GetVarRecordByIndex(*(char **)&data_ov026_02091368 + 0xc130, entry), -1);
    Ov026_RefreshPanelDisplay();
    return (void *)&Ov026_Shop_QuantityDialogTick;
}
