extern char *data_ov008_02090fac;
extern void Ov008_Shop_LayoutPage(int arg);
extern void Ov008_ShowCounterPanel(void);
extern void Ov008_DrawTitleBar(int caption);
extern void Ov008_Stats_CreateRowCells(void);
extern void Ov008_BuildTotalsPanel(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_SelectionIdleTick(void);
extern void Ov008_ShopListInput(void);

/* Rebuilds the list for the current tab and picks the next state: the idle tick if the list is
 * live, otherwise straight back out. */
void *Ov008_RebuildTabList(void) {
    char *st = *(char **)&data_ov008_02090fac;
    int caption;
    int tab;
    Ov008_Shop_LayoutPage(*(int *)(st + 0xc3d4));
    Ov008_ShowCounterPanel();
    switch (*(int *)(st + 0xc250)) {
    case 0:
        caption = 0xc;
        break;
    case 1:
        caption = 0xf;
        break;
    case 2:
        caption = 0x12;
        break;
    case 3:
        caption = 0x18;
        break;
    }
    Ov008_DrawTitleBar(caption);
    tab = *(int *)(st + 0xc250);
    if (tab == 2 && *(int *)(st + 0xc3d4) != 0) {
        Ov008_Stats_CreateRowCells();
    } else if (tab == 3) {
        Ov008_BuildTotalsPanel();
    }
    Ov008_RefreshPanelDisplay();
    *(int *)st = 0;
    if (*(int *)(st + 0xc3d4) != 0 && *(int *)(st + 0xc56c) != 0) {
        return (void *)&Ov008_SelectionIdleTick;
    }
    return (void *)&Ov008_ShopListInput;
}
