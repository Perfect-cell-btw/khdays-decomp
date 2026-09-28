/* Ov008_RefreshPanelDisplay -- Ov008_RefreshPanelDisplay (212 B, 16 relocs).
 * Rebuilds the visible menu panel from the shared panel context (*data_ov008_02090fac).
 * Brackets the work with Ov008_PanelRefresh / Ov008_FlushDirtyVramBanks. When the enable word at
 * ctx+0xc5f8 is set, it re-applies the highlighted widget (id 0xa in the widget group at
 * ctx+0x2ab0) to the current value from Ov105_WM_GetLinkLevel (masked to u16). It then appends a
 * fresh cell (Ov008_FindEntryByTag tag 0x3e8 -> Ov008_TagTracker_InvokeCallback) to the list at ctx+0x5c,
 * closes the four render surfaces (ctx+0xc19c/0xc1d8/0xc214/0xc160), clears the scroll on the two
 * widget groups (ctx+0x7530 and ctx+0x2ab0), and tears down the two sub-panels (ctx+0x5c, ctx+0x10). */
#include "nitro/types.h"

extern char *data_ov008_02090fac;
extern void  Ov008_PanelRefresh(void);
extern void *Ov008_FindEntryById(void *ctx, int id);
extern void  Ov008_ReleaseTwoSlotsEx(void *ctx, void *widget, int value);
extern int   Ov105_WM_GetLinkLevel(void);
extern int   Ov008_FindEntryByTag(void *list, int tag);
extern void  Ov008_TagTracker_InvokeCallback(void *list, int cell);
extern void  EnqueueObjGfxCommand(void *surface);
extern void  Ov008_UpdateWidgetLayerDefault(void *arg0, int arg1);
extern void  Ov008_TickSelectionWidget(void *arg);
extern void  Ov008_FlushDirtyVramBanks(void);

void Ov008_RefreshPanelDisplay(void)
{
    char *ctx = data_ov008_02090fac;

    Ov008_PanelRefresh();
    if (*(int *)(ctx + 0xc5f8) != 0) {
        void *widget = Ov008_FindEntryById(ctx + 0x2ab0, 0xa);
        Ov008_ReleaseTwoSlotsEx(ctx + 0x2ab0, widget, (u16)Ov105_WM_GetLinkLevel());
    }
    Ov008_TagTracker_InvokeCallback(ctx + 0x5c, Ov008_FindEntryByTag(ctx + 0x5c, 0x3e8));
    EnqueueObjGfxCommand(ctx + 0xc19c);
    EnqueueObjGfxCommand(ctx + 0xc1d8);
    EnqueueObjGfxCommand(ctx + 0xc214);
    EnqueueObjGfxCommand(ctx + 0xc160);
    Ov008_UpdateWidgetLayerDefault(ctx + 0x7530, 0);
    Ov008_UpdateWidgetLayerDefault(ctx + 0x2ab0, 0);
    Ov008_TickSelectionWidget(ctx + 0x5c);
    Ov008_TickSelectionWidget(ctx + 0x10);
    Ov008_FlushDirtyVramBanks();
}
