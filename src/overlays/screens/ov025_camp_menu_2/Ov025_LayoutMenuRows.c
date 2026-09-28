/* Ov025_LayoutMenuRows -- Ov008_LayoutMenuRows (240 B, 9 relocs).
 * Lays out a vertical run of menu widgets in FX32 (<<12) coordinates. Reads a shared base value
 * (Ov025_GetEntryBlock2c on widget 2) into wp.base, computes the row origin r5 = ctx->field20 +
 * ctx->field14, then positions widgets 4..0x13 at y = ((i-4)*8 + 0x10 + r5), widget 2 at y = r5,
 * and widget 3 at y = r5 + ctx->field24 - 0x10, each pushed through Ov025_ReleaseTwoSlotsEx with the
 * {base, pos} pair. The row-offset add is written `p += r5` so the freshly-built offset (not the
 * loop-invariant r5) is the dying operand mwcc reuses for the destination register. */

#include "nitro/types.h"

typedef struct WidgetPos {
    int base;   /* 0x0: shared base value from Ov025_GetEntryBlock2c */
    int pos;    /* 0x4: per-widget FX32 position */
} WidgetPos;

typedef struct Ov008LayoutCtx {
    u8  pad_0000[0x14];
    int field14;   /* 0x14 */
    u8  pad_0018[0x8];
    int field20;   /* 0x20 */
    int field24;   /* 0x24 */
} Ov008LayoutCtx;

extern void *Ov025_GetBlock4a80(void);
extern void *Ov025_FindEntryById(void *wctx, int id);
extern int  *Ov025_GetEntryBlock2c(void *wctx, void *w);
extern void  Ov025_ReleaseTwoSlotsEx(void *wctx, void *w, WidgetPos *wp);

void Ov025_LayoutMenuRows(Ov008LayoutCtx *ctx)
{
    void *wctx = Ov025_GetBlock4a80();
    WidgetPos wp = {0, 0};
    int r5;
    int i;

    wp.base = *Ov025_GetEntryBlock2c(wctx, Ov025_FindEntryById(wctx, 2));
    r5 = ctx->field20 + ctx->field14;
    for (i = 4; i <= 0x13; i++) {
        int p = (i - 4) * 8 + 0x10;
        p += r5;
        wp.pos = p << 12;
        Ov025_ReleaseTwoSlotsEx(wctx, Ov025_FindEntryById(wctx, i), &wp);
    }
    wp.pos = r5 << 12;
    Ov025_ReleaseTwoSlotsEx(wctx, Ov025_FindEntryById(wctx, 2), &wp);
    wp.pos = (r5 + ctx->field24 - 0x10) << 12;
    Ov025_ReleaseTwoSlotsEx(wctx, Ov025_FindEntryById(wctx, 3), &wp);
}
