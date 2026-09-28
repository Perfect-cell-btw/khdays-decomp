extern char *data_ov026_02091368;
extern void Ov026_InitFilterRows(void);
extern void Ov026_DrawTitleBar(int a);
extern int Ov026_GetVarRecordByIndex(void *p, int a);
extern void Ov026_DrawStringShadowed(void *dst, int src, int a, int b, int c, int d);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_SelectionFadeInTick(void);
extern void Ov026_ShopEnterTabSelectWhenReady(void);

/* Enters the selection screen: builds the layout, blits the caption, marks every VRAM bank dirty
 * and picks the fade-in or the instant-show tick. */
void *Ov026_EnterSelectionScreen(void) {
    int caption;
    void *next;
    Ov026_InitFilterRows();
    Ov026_DrawTitleBar(5);
    caption = Ov026_GetVarRecordByIndex(*(char **)&data_ov026_02091368 + 0xc130, 6);
    Ov026_DrawStringShadowed(*(char **)&data_ov026_02091368 + 0xc1d8, caption, 8, 8, 4, 8);
    *(int *)(*(char **)&data_ov026_02091368 + 0x2aac) |= 0x7f;
    Ov026_RefreshPanelDisplay();
    if (*(int *)(*(char **)&data_ov026_02091368 + 0xc3d8) == 0) {
        next = (void *)&Ov026_SelectionFadeInTick;
    } else {
        next = (void *)&Ov026_ShopEnterTabSelectWhenReady;
    }
    return next;
}
