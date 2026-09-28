/*
 * Ov002_ReturnFromMapToPanel - come back from the map and take the screen
 * again, unless a panel request is already waiting.
 *
 * The scroll tween finishing retunes the ambient emitter, and that runs before
 * the gate. Past it, a pending request short-circuits the whole thing: the
 * state drops to 0 and the screen is given up, which lets whatever asked for
 * the panel start it from the top.
 *
 * Otherwise the map snapshot is taken back, the entry selection is dropped,
 * the blend fades to 0x10 over 300, the screen is claimed and the state moves
 * to 0xb. The label surface is flushed on the way out if it was ever built.
 *
 * ARM.
 */

typedef struct {
    char pad0000[0x3c];
    int nPanelRequestValue;             /* +0x03c */
    int bOwnsScreen;                    /* +0x040 */
    int bLabelsBuilt;                   /* +0x044 */
    char pad0048[0x24];
    int aTextSurface[1];                /* +0x06c sTextSurface */
    char pad0070[0xbc];
    unsigned int dwScrollTweenFlags;    /* +0x12c Tween.dwFlags, bit 2 = finished */
    char pad0130[0x5c];
    int nPanelState;                    /* +0x18c */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f614;

extern void EnqueueObjGfxCommand(int *pSurface);
extern void Ov002_StartBlendFade(int a, int b, int nDuration);
extern void Ov002_PopMapSnapshot(void);
extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_RetuneAmbientEmitter(void);
extern void Ov002_HudRefreshPlayer(void);
extern int Ov002_ScenePanel_IsIdle(void);

void Ov002_ReturnFromMapToPanel(void)
{
    Ov002PanelContext *ctx;

    ctx = data_ov002_0207f614;
    if (((unsigned int)((int)ctx->dwScrollTweenFlags << 0x1d) >> 0x1f) != 0) {
        Ov002_RetuneAmbientEmitter();
    }
    if (Ov002_ScenePanel_IsIdle() == 0) {
        return;
    }

    if (ctx->nPanelRequestValue != 0) {
        ctx->nPanelState = 0;
        ctx->bOwnsScreen = 0;
        return;
    }

    Ov002_PopMapSnapshot();
    Ov002_SelectEntryByKey(-1);
    Ov002_HudRefreshPlayer();
    Ov002_StartBlendFade(0, 0x10, 300);
    ctx->bOwnsScreen = 1;
    ctx->nPanelState = 0xb;
    if (ctx->bLabelsBuilt != 0) {
        EnqueueObjGfxCommand(ctx->aTextSurface);
    }
}
