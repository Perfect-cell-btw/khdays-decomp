extern char *data_ov026_02091368;
extern void Ov026_Shop_LayoutPage(int arg);
extern void Ov026_ShowCounterPanel(void);
extern void Ov026_DrawTitleBar(int caption);
extern void Ov026_Stats_CreateRowCells(void);
extern void Ov026_BuildTotalsPanel(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_SelectionIdleTick(void);
extern void Ov026_ShopListInput(void);

/* Rebuilds the list for the current tab and picks the next state: the idle tick if the list is
 * live, otherwise straight back out. */
void *Ov026_RebuildTabList(void) {
    char *st = *(char **)&data_ov026_02091368;
    int caption;
    int tab;
    Ov026_Shop_LayoutPage(*(int *)(st + 0xc3d4));
    Ov026_ShowCounterPanel();
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
    Ov026_DrawTitleBar(caption);
    tab = *(int *)(st + 0xc250);
    if (tab == 2 && *(int *)(st + 0xc3d4) != 0) {
        Ov026_Stats_CreateRowCells();
    } else if (tab == 3) {
        Ov026_BuildTotalsPanel();
    }
    Ov026_RefreshPanelDisplay();
    *(int *)st = 0;
    if (*(int *)(st + 0xc3d4) != 0 && *(int *)(st + 0xc56c) != 0) {
        return (void *)&Ov026_SelectionIdleTick;
    }
    return (void *)&Ov026_ShopListInput;
}
