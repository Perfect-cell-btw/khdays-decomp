/* Ov025_ApplyModeWidgets2 -- Ov008_ApplyModeWidgets2 (380 B, 26 relocs).
 * Twin of Ov008_ApplyModeWidgets: identical two-state widget reconfiguration of menu widgets
 * 0x35..0x38, differing only in the state field it tracks (ctx->selected at 0x184 here vs 0x4fc
 * there). See Ov008_ApplyModeWidgets for the full per-widget breakdown. */

#include "nitro/types.h"

typedef struct Ov008ModeCtx {
    u8  pad_0000[0x184];
    int selected;   /* 0x184: last applied mode */
} Ov008ModeCtx;

extern void *Ov025_GetBlock4a80(void);
extern void *Ov025_FindEntryById(void *wctx, int id);
extern void  Ov025_ReleaseTwoSlotsEx_2(void *wctx, void *w, int val);
extern void  Ov025_SwapParamOverrides(void *wctx, void *w);
extern void  Ov025_PushSubitemPair(void *wctx, void *w, int arg);
extern void  Ov025_SetEntrySlotsVisible(void *wctx, void *w, int flag);
extern void  PlaySound(int a, int b);

void Ov025_ApplyModeWidgets2(Ov008ModeCtx *ctx, int mode)
{
    void *wctx = Ov025_GetBlock4a80();
    if (mode != 0) {
        Ov025_ReleaseTwoSlotsEx_2(wctx, Ov025_FindEntryById(wctx, 0x35), 0);
        Ov025_ReleaseTwoSlotsEx_2(wctx, Ov025_FindEntryById(wctx, 0x36), 0);
        Ov025_SwapParamOverrides(wctx, Ov025_FindEntryById(wctx, 0x35));
        Ov025_PushSubitemPair(wctx, Ov025_FindEntryById(wctx, 0x36), 0);
        Ov025_SetEntrySlotsVisible(wctx, Ov025_FindEntryById(wctx, 0x37), 1);
        Ov025_SetEntrySlotsVisible(wctx, Ov025_FindEntryById(wctx, 0x38), 0);
    } else {
        Ov025_ReleaseTwoSlotsEx_2(wctx, Ov025_FindEntryById(wctx, 0x35), 0);
        Ov025_ReleaseTwoSlotsEx_2(wctx, Ov025_FindEntryById(wctx, 0x36), 0);
        Ov025_SwapParamOverrides(wctx, Ov025_FindEntryById(wctx, 0x36));
        Ov025_PushSubitemPair(wctx, Ov025_FindEntryById(wctx, 0x35), 0);
        Ov025_SetEntrySlotsVisible(wctx, Ov025_FindEntryById(wctx, 0x37), 0);
        Ov025_SetEntrySlotsVisible(wctx, Ov025_FindEntryById(wctx, 0x38), 1);
    }
    if (ctx->selected != mode) {
        PlaySound(0, 0);
    }
    ctx->selected = mode;
}
