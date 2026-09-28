/* Ov008_LayoutMenuRows2 -- Ov008_LayoutMenuRows2 (244 B, 9 relocs).
 * Sibling of Ov008_LayoutMenuRows for a different menu screen. Sets the row origin
 * ctx->field2fc = arg1 + 0x18, reads a shared base (Ov008_GetEntryBlock2c on widget 0xd) into the
 * {base,pos} pair, then lays out widgets 0xf..0x1a at ((field2fc + (i-0xf)*8 + 0x10) << 12),
 * widget 0xd at (field2fc << 12), and widget 0xe at ((field2fc + ctx->field2f8 - 0x10) << 12),
 * each pushed via Ov008_SetEntryPos. field2fc is re-read from the object each iteration
 * (matching the ROM's per-iteration load). */
#include "nitro/types.h"

typedef struct WidgetPos {
    int base;   /* 0x0 */
    int pos;    /* 0x4 */
} WidgetPos;

typedef struct Ov008LayoutCtx2 {
    u8  pad_0000[0x2f8];
    int field2f8;   /* 0x2f8 */
    int field2fc;   /* 0x2fc: row origin (set from arg1 + 0x18) */
} Ov008LayoutCtx2;

extern void *Ov008_GetContext(void);
extern void *Ov008_FindEntryById(void *wctx, int id);
extern int  *Ov008_GetEntryBlock2c(void *wctx, void *w);
extern void  Ov008_SetEntryPos(void *wctx, void *w, WidgetPos *wp);

void Ov008_LayoutMenuRows2(Ov008LayoutCtx2 *ctx, int arg1)
{
    WidgetPos wp = {0, 0};
    void *wctx;
    int i;

    ctx->field2fc = arg1 + 0x18;
    wctx = Ov008_GetContext();
    wp.base = *Ov008_GetEntryBlock2c(wctx, Ov008_FindEntryById(wctx, 0xd));
    for (i = 0xf; i <= 0x1a; i++) {
        wp.pos = (ctx->field2fc + (i - 0xf) * 8 + 0x10) << 12;
        Ov008_SetEntryPos(wctx, Ov008_FindEntryById(wctx, i), &wp);
    }
    wp.pos = ctx->field2fc << 12;
    Ov008_SetEntryPos(wctx, Ov008_FindEntryById(wctx, 0xd), &wp);
    wp.pos = (ctx->field2fc + ctx->field2f8 - 0x10) << 12;
    Ov008_SetEntryPos(wctx, Ov008_FindEntryById(wctx, 0xe), &wp);
}
