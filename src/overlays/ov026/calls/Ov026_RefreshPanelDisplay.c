/* Ov026_RefreshPanelDisplay -- Ov008_RefreshPanelDisplay (212 B, 16 relocs).
 * Rebuilds the visible menu panel from the shared panel context (*data_ov026_02091368).
 * Brackets the work with Ov026_PanelRefresh / Ov026_FlushDirtyVramBanks. When the enable word at
 * ctx+0xc5f8 is set, it re-applies the highlighted widget (id 0xa in the widget group at
 * ctx+0x2ab0) to the current value from Ov105_WM_GetLinkLevel (masked to u16). It then appends a
 * fresh cell (Ov026_FindEntryByTag tag 0x3e8 -> Ov026_TagTracker_InvokeCallback) to the list at ctx+0x5c,
 * closes the four render surfaces (ctx+0xc19c/0xc1d8/0xc214/0xc160), clears the scroll on the two
 * widget groups (ctx+0x7530 and ctx+0x2ab0), and tears down the two sub-panels (ctx+0x5c, ctx+0x10). */
typedef unsigned char u8;
typedef unsigned short u16;

extern char *data_ov026_02091368;
extern void  Ov026_PanelRefresh(void);
extern void *Ov026_FindEntryById(void *ctx, int id);
extern void  Ov026_ReleaseTwoSlotsEx_2(void *ctx, void *widget, int value);
extern int   Ov105_WM_GetLinkLevel(void);
extern int   Ov026_FindEntryByTag(void *list, int tag);
extern void  Ov026_TagTracker_InvokeCallback(void *list, int cell);
extern void  EnqueueObjGfxCommand(void *surface);
extern void  Ov026_UpdateWidgetLayerDefault(void *arg0, int arg1);
extern void  Ov026_TickSelectionWidget(void *arg);
extern void  Ov026_FlushDirtyVramBanks(void);

void Ov026_RefreshPanelDisplay(void)
{
    char *ctx = data_ov026_02091368;

    Ov026_PanelRefresh();
    if (*(int *)(ctx + 0xc5f8) != 0) {
        void *widget = Ov026_FindEntryById(ctx + 0x2ab0, 0xa);
        Ov026_ReleaseTwoSlotsEx_2(ctx + 0x2ab0, widget, (u16)Ov105_WM_GetLinkLevel());
    }
    Ov026_TagTracker_InvokeCallback(ctx + 0x5c, Ov026_FindEntryByTag(ctx + 0x5c, 0x3e8));
    EnqueueObjGfxCommand(ctx + 0xc19c);
    EnqueueObjGfxCommand(ctx + 0xc1d8);
    EnqueueObjGfxCommand(ctx + 0xc214);
    EnqueueObjGfxCommand(ctx + 0xc160);
    Ov026_UpdateWidgetLayerDefault(ctx + 0x7530, 0);
    Ov026_UpdateWidgetLayerDefault(ctx + 0x2ab0, 0);
    Ov026_TickSelectionWidget(ctx + 0x5c);
    Ov026_TickSelectionWidget(ctx + 0x10);
    Ov026_FlushDirtyVramBanks();
}
