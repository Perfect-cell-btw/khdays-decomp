/*
 * Ov002_HoldAfterTextCrawl - wait out the pause at the end of the crawl, then
 * hand the panel to the fade-in.
 *
 * The scroll tween finishing is what retunes the ambient emitter, and that is
 * checked every frame regardless. The panel then leaves this state either
 * because the hold has run out - a zero hold means there is none, so only the
 * skip can end it - or because the skip flag is set.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct {
    char pad0000[0x48];
    int bSkipCrawl;                     /* +0x048 */
    char pad004c[0xe0];
    unsigned int dwScrollTweenFlags;    /* +0x12c Tween.dwFlags, bit 2 = finished */
    char pad0130[0x5c];
    int nPanelState;                    /* +0x18c */
    char pad0190[0xc4];
    u64 nCrawlLastTick;                 /* +0x254 */
    u64 nCrawlHoldTicks;                /* +0x25c */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f614;

extern u64 OS_GetTick(void);
extern void Ov002_RetuneAmbientEmitter(void);
extern void Ov002_StartPanelFadeIn(void);

void Ov002_HoldAfterTextCrawl(void)
{
    Ov002PanelContext *ctx;
    u64 nNow;
    u64 nElapsed;

    ctx = data_ov002_0207f614;
    nNow = OS_GetTick();
    nElapsed = nNow - ctx->nCrawlLastTick;
    if (((unsigned int)((int)ctx->dwScrollTweenFlags << 0x1d) >> 0x1f) != 0) {
        Ov002_RetuneAmbientEmitter();
    }

    if ((ctx->nCrawlHoldTicks != 0 && ctx->nCrawlHoldTicks <= nElapsed) ||
        ctx->bSkipCrawl != 0) {
        Ov002_StartPanelFadeIn();
        ctx->nPanelState = 6;
    }
}
