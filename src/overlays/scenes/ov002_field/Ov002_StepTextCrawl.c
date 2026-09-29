/*
 * Ov002_StepTextCrawl - type out one more glyph of the panel's text crawl.
 *
 * Real elapsed time is accumulated from the tick counter, so a dropped frame
 * does not slow the crawl down: one glyph every 0x4380 ticks, and the consumed
 * time is taken back out with a 64-bit modulo rather than cleared, which keeps
 * a long stall from drifting instead of skipping.
 *
 * Two things dump the rest of the line at once - the skip flag at +0x48, and a
 * pen already past 0xff. Either way the crawl ends in state 5, and so does
 * sitting 0xfb790 ticks past the end of the string. The skip flag also runs
 * the fade-in and parks the panel in state 6 instead.
 *
 * ARM.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    char pad0000[0x48];
    int bSkipRequested;                 /* +0x048 */
    char pad004c[0x140];
    int nPanelState;                    /* +0x18c */
    char pad0190[0x30];
    u16 *pCrawlText;                    /* +0x1c0 */
    char pad01c4[0x80];
    int nCrawlIndex;                    /* +0x244 */
    int nCrawlPenX;                     /* +0x248 */
    u64 nCrawlElapsed;                  /* +0x24c */
    u64 nCrawlLastTick;                 /* +0x254 */
    char pad025c[8];
    int aCrawlSurface[1];               /* +0x264 sCrawlSurface */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f614;

extern u64 OS_GetTick(void);
extern u64 func_02020374(u64 a, u64 b);
extern void EnqueueObjGfxCommand(int *pSurface);
extern void Ov002_RetuneAmbientEmitter(void);
extern void Ov002_StartPanelFadeIn(void);

void Ov002_StepTextCrawl(void)
{
    Ov002PanelContext *ctx;
    u64 nNow;
    int i;

    ctx = data_ov002_0207f614;
    nNow = OS_GetTick();
    ctx->nCrawlElapsed += nNow - ctx->nCrawlLastTick;

    if (ctx->bSkipRequested != 0 || ctx->nCrawlPenX > 0xff) {
        i = ctx->nCrawlIndex;
        while (ctx->pCrawlText[i] != 0) {
            ctx->nCrawlIndex = ctx->nCrawlIndex + 1;
            ctx->nCrawlPenX += Obj_ForwardInnerPayload(ctx->aCrawlSurface, ctx->nCrawlPenX,
                                             3, 2, ctx->pCrawlText[i]);
            i = ctx->nCrawlIndex;
        }
        EnqueueObjGfxCommand(ctx->aCrawlSurface);
        if (ctx->nCrawlPenX > 0xff) {
            Ov002_RetuneAmbientEmitter();
            ctx->nPanelState = 5;
        }
    } else if (ctx->nCrawlElapsed > 0x4380) {
        i = ctx->nCrawlIndex;
        if (ctx->pCrawlText[i] == 0) {
            if (ctx->nCrawlElapsed >= 0xfb790) {
                Ov002_RetuneAmbientEmitter();
                ctx->nPanelState = 5;
            }
        } else {
            ctx->nCrawlIndex = i + 1;
            ctx->nCrawlPenX += Obj_ForwardInnerPayload(ctx->aCrawlSurface, ctx->nCrawlPenX,
                                             3, 2, ctx->pCrawlText[i]);
            EnqueueObjGfxCommand(ctx->aCrawlSurface);
            ctx->nCrawlElapsed = func_02020374(ctx->nCrawlElapsed, 0x4380);
        }
    }

    ctx->nCrawlLastTick = nNow;
    if (ctx->bSkipRequested != 0) {
        Ov002_StartPanelFadeIn();
        ctx->nPanelState = 6;
    }
}
