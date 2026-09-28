extern char *data_ov008_02090fac;
extern int Ov008_FadeInStep(void);
extern void Ov008_UpdateTouchState(void);
extern void Ov008_ShopRefreshSelection(void);
extern void Ov008_UpdateScrollArrows_3(void);
extern void Ov008_DrawTradePanel(void);
extern void Ov008_RedrawBothColumns(void);
extern void Ov008_DrawCounterPanel(void *entry, int arg);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_ShopListInput(void);

/* Idle tick of the selection screen: runs the fade, polls touch, refreshes the arrows, and then
 * whatever the current tab needs redrawing. */
void *Ov008_SelectionIdleTick(void) {
    char *view;
    char *st = *(char **)&data_ov008_02090fac;
    void *next;
    int tab;
    char **rows;
    view = st + 0xc3c4;
    if (Ov008_FadeInStep() != 0) {
        next = (void *)&Ov008_ShopListInput;
    } else {
        next = 0;
    }
    Ov008_UpdateTouchState();
    Ov008_ShopRefreshSelection();
    Ov008_UpdateScrollArrows_3();
    tab = *(int *)(st + 0xc250);
    if (tab == 2) {
        *(int *)(view + 0x100) = 1;
        Ov008_DrawTradePanel();
        Ov008_RedrawBothColumns();
    } else if (tab != 3) {
        rows = *(char ***)(view + 0xc);
        Ov008_DrawCounterPanel(rows != 0 ? rows[*(int *)view] : 0, -1);
    }
    Ov008_RefreshPanelDisplay();
    return next;
}
