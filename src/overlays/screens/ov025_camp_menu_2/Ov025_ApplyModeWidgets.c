/* Ov025_ApplyModeWidgets -- Ov008_ApplyModeWidgets (380 B, 26 relocs).
 * Reconfigures the menu widgets 0x35..0x38 for a two-state mode toggle. When mode != 0 it wires
 * the pair (0x35 -> "checked" via Ov025_SwapParamOverrides, 0x36 -> "unchecked" via
 * Ov025_PushSubitemPair) and enables widget 0x37 / disables 0x38; when mode == 0 it swaps the pair
 * (0x36 checked, 0x35 unchecked) and disables 0x37 / enables 0x38. Both branches first zero the
 * values of 0x35 and 0x36 (Ov025_ReleaseTwoSlotsEx_2). If the applied mode changed since last time
 * (ctx->selected), it fires PlaySound(0, 0), then stores the new mode. Twin of
 * Ov008_ApplyModeWidgets2 (same shape, ctx->selected at 0x184 there). */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008ModeCtx {
    u8  pad_0000[0x4fc];
    int selected;   /* 0x4fc: last applied mode */
} Ov008ModeCtx;

extern void *Ov025_GetBlock4a80(void);
extern void *Ov025_FindEntryById(void *wctx, int id);
extern void  Ov025_ReleaseTwoSlotsEx_2(void *wctx, void *w, int val);
extern void  Ov025_SwapParamOverrides(void *wctx, void *w);
extern void  Ov025_PushSubitemPair(void *wctx, void *w, int arg);
extern void  Ov025_SetEntrySlotsVisible(void *wctx, void *w, int flag);

void Ov025_ApplyModeWidgets(Ov008ModeCtx *ctx, int mode)
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
