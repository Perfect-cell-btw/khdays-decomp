extern char *data_ov008_02090fac;
extern void Ov008_InitFilterRows(void);
extern void Ov008_DrawTitleBar(int a);
extern int Ov008_GetVarRecordByIndex(void *p, int a);
extern void Ov008_DrawStringShadowed(void *dst, int src, int a, int b, int c, int d);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_SelectionFadeInTick(void);
extern void Ov008_ShopEnterTabSelectWhenReady(void);

/* Enters the selection screen: builds the layout, blits the caption, marks every VRAM bank dirty
 * and picks the fade-in or the instant-show tick. */
void *Ov008_EnterSelectionScreen(void) {
    int caption;
    void *next;
    Ov008_InitFilterRows();
    Ov008_DrawTitleBar(5);
    caption = Ov008_GetVarRecordByIndex(*(char **)&data_ov008_02090fac + 0xc130, 6);
    Ov008_DrawStringShadowed(*(char **)&data_ov008_02090fac + 0xc1d8, caption, 8, 8, 4, 8);
    *(int *)(*(char **)&data_ov008_02090fac + 0x2aac) |= 0x7f;
    Ov008_RefreshPanelDisplay();
    if (*(int *)(*(char **)&data_ov008_02090fac + 0xc3d8) == 0) {
        next = (void *)&Ov008_SelectionFadeInTick;
    } else {
        next = (void *)&Ov008_ShopEnterTabSelectWhenReady;
    }
    return next;
}
