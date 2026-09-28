extern char *data_ov026_02091368;
extern int Ov026_FadeInStep(void);
extern void Ov026_UpdateTouchState(void);
extern void Ov026_ShopRefreshSelection(void);
extern void Ov026_UpdateScrollArrows(void);
extern void Ov026_DrawTradePanel(void);
extern void Ov026_RedrawBothColumns(void);
extern void Ov026_DrawCounterPanel(void *entry, int arg);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_ShopListInput(void);

/* Idle tick of the selection screen: runs the fade, polls touch, refreshes the arrows, and then
 * whatever the current tab needs redrawing. */
void *Ov026_SelectionIdleTick(void) {
    char *view;
    char *st = *(char **)&data_ov026_02091368;
    void *next;
    int tab;
    char **rows;
    view = st + 0xc3c4;
    if (Ov026_FadeInStep() != 0) {
        next = (void *)&Ov026_ShopListInput;
    } else {
        next = 0;
    }
    Ov026_UpdateTouchState();
    Ov026_ShopRefreshSelection();
    Ov026_UpdateScrollArrows();
    tab = *(int *)(st + 0xc250);
    if (tab == 2) {
        *(int *)(view + 0x100) = 1;
        Ov026_DrawTradePanel();
        Ov026_RedrawBothColumns();
    } else if (tab != 3) {
        rows = *(char ***)(view + 0xc);
        Ov026_DrawCounterPanel(rows != 0 ? rows[*(int *)view] : 0, -1);
    }
    Ov026_RefreshPanelDisplay();
    return next;
}
