/* Point the scene's tile surface at +0x6c at the item held in +0xb8, but only
 * once Ov002_Hud_IsPanelOpen reports the transition finished. The relayout at
 * Ov002_FlushQueuedRequests runs first, so the surface is retargeted against fresh
 * geometry. */
typedef struct {
    char pad00[0x6c];
    char surface[0x3c];     /* +0x6c TileSurface */
    char pada8[0x10];
    int pCurrentItem;       /* +0xb8 */
} Ov002PanelContext;

extern int Ov002_Hud_IsPanelOpen(void);
extern void Ov002_FlushQueuedRequests(void);
extern void TileSurface_SetCurrentItem(void *surface, int item, int a);

extern Ov002PanelContext *data_ov002_0207f614;

void Ov002_RetargetPanelSurface(void) {
    Ov002PanelContext *ctx = data_ov002_0207f614;

    if (Ov002_Hud_IsPanelOpen() != 0) {
        return;
    }

    Ov002_FlushQueuedRequests();
    TileSurface_SetCurrentItem(ctx->surface, ctx->pCurrentItem, 1);
}
