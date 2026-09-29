/* Ov008_ApplyModeWidgets2 -- Ov008_ApplyModeWidgets2 (380 B, 26 relocs).
 * Twin of Ov008_ApplyModeWidgets: identical two-state widget reconfiguration of menu widgets
 * 0x35..0x38, differing only in the state field it tracks (ctx->selected at 0x184 here vs 0x4fc
 * there). See Ov008_ApplyModeWidgets for the full per-widget breakdown. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008ModeCtx {
    u8  pad_0000[0x184];
    int selected;   /* 0x184: last applied mode */
} Ov008ModeCtx;

extern void *Ov008_GetCtxBlock4a80(void);
extern void *Ov008_FindEntryById(void *wctx, int id);
extern void  Ov008_ReleaseTwoSlotsEx(void *wctx, void *w, int val);
extern void  Ov008_SwapParamOverrides(void *wctx, void *w);
extern void  Ov008_PushSubitemPair(void *wctx, void *w, int arg);
extern void  Ov008_SetEntrySlotsVisible(void *wctx, void *w, int flag);

void Ov008_ApplyModeWidgets2(Ov008ModeCtx *ctx, int mode)
{
    void *wctx = Ov008_GetCtxBlock4a80();
    if (mode != 0) {
        Ov008_ReleaseTwoSlotsEx(wctx, Ov008_FindEntryById(wctx, 0x35), 0);
        Ov008_ReleaseTwoSlotsEx(wctx, Ov008_FindEntryById(wctx, 0x36), 0);
        Ov008_SwapParamOverrides(wctx, Ov008_FindEntryById(wctx, 0x35));
        Ov008_PushSubitemPair(wctx, Ov008_FindEntryById(wctx, 0x36), 0);
        Ov008_SetEntrySlotsVisible(wctx, Ov008_FindEntryById(wctx, 0x37), 1);
        Ov008_SetEntrySlotsVisible(wctx, Ov008_FindEntryById(wctx, 0x38), 0);
    } else {
        Ov008_ReleaseTwoSlotsEx(wctx, Ov008_FindEntryById(wctx, 0x35), 0);
        Ov008_ReleaseTwoSlotsEx(wctx, Ov008_FindEntryById(wctx, 0x36), 0);
        Ov008_SwapParamOverrides(wctx, Ov008_FindEntryById(wctx, 0x36));
        Ov008_PushSubitemPair(wctx, Ov008_FindEntryById(wctx, 0x35), 0);
        Ov008_SetEntrySlotsVisible(wctx, Ov008_FindEntryById(wctx, 0x37), 0);
        Ov008_SetEntrySlotsVisible(wctx, Ov008_FindEntryById(wctx, 0x38), 1);
    }
    if (ctx->selected != mode) {
        PlaySound(0, 0);
    }
    ctx->selected = mode;
}
