/*
 * Ov002_FinishPanelFadeIn - once the fade-in tween has run out, park it, take
 * the map snapshot back, and start the panel sliding away.
 *
 * The offset tween finishing is what drives this. It is stopped by rewriting
 * it as a zero-length tween, the map snapshot the panel pushed is popped, and
 * the blend fades to 0x10 over 300. Then, only while the flip gate is open,
 * one of two things happens: with the flag at +0x2a4 set the crawl's text is
 * handed on and nothing else runs, otherwise the level it reads is stored and
 * - unless the mode bits select the middle case, or the level is already 0xf6
 * or more - the scroll tween starts its long 18000 run.
 *
 * The panel is then put back in main-screen mode, the offset tween is turned
 * around to slide from 0x18000 back to zero over 300, and the state moves to 7.
 *
 * While the offset tween is still running there is nothing to do but retune
 * the ambient emitter when the scroll tween finishes.
 *
 * ARM.
 */

typedef unsigned char u8;

typedef struct {
    int nFlipGate;                      /* +0x000 */
    char pad0004[0xf4];
    char aOffsetTween[0x18];            /* +0x0f8 */
    unsigned int dwOffsetTweenFlags;    /* +0x110 Tween.dwFlags, bit 2 = finished */
    char aScrollTween[0x18];            /* +0x114 */
    unsigned int dwScrollTweenFlags;    /* +0x12c Tween.dwFlags, bit 2 = finished */
    char pad0130[0x5c];
    int nPanelState;                    /* +0x18c */
    char pad0190[0x30];
    int pCrawlText;                     /* +0x1c0 */
    int aLevels[2];                     /* +0x1c4 */
    char pad01cc[0xd8];
    int bTextHandOff;                   /* +0x2a4 */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f614;
extern u8 data_0204c240;

extern void Tween_Configure(void *pTween, int nMode, int nFrom, int nTo,
                          int nDuration);
extern void Tween_Start(void *pTween);
extern void Ov002_StartBlendFade(int a, int b, int nDuration);
extern void Ov002_PopMapSnapshot(void);
extern void Ov002_RetuneAmbientEmitter(void);
extern void Ov002_SetPanelMode(int nMode);
extern void Ov002_SetCaptionText(int pText);
extern int Ov002_Field_GetWordB0(void);

void Ov002_FinishPanelFadeIn(void)
{
    Ov002PanelContext *ctx;

    ctx = data_ov002_0207f614;
    if (((unsigned int)((int)ctx->dwOffsetTweenFlags << 0x1d) >> 0x1f) != 0) {
        Tween_Configure(ctx->aOffsetTween, 0, 0, 0, 0);
        Tween_Start(ctx->aOffsetTween);
        Ov002_PopMapSnapshot();
        Ov002_StartBlendFade(0, 0x10, 300);
        if (ctx->nFlipGate != 0) {
            if (ctx->bTextHandOff != 0) {
                Ov002_SetCaptionText(ctx->pCrawlText);
            } else {
                ctx->aLevels[0] = Ov002_Field_GetWordB0();
                if ((data_0204c240 & 6) != 2 && ctx->aLevels[0] < 0xf6) {
                    Tween_Configure(ctx->aScrollTween, 0, 0, 0, 18000);
                    Tween_Start(ctx->aScrollTween);
                }
            }
        }
        Ov002_SetPanelMode(0);
        Tween_Configure(ctx->aOffsetTween, 2, 0x18000, 0, 300);
        Tween_Start(ctx->aOffsetTween);
        ctx->nPanelState = 7;
        return;
    }

    if (((unsigned int)((int)ctx->dwScrollTweenFlags << 0x1d) >> 0x1f) != 0) {
        Ov002_RetuneAmbientEmitter();
    }
}
