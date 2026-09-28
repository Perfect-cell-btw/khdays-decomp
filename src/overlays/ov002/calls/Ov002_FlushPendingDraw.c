/* Flush the pending draw, if there is one: hand the surface to the encoder, run
 * the flush tail, then clear the pending slot. */
extern void *Ov002_Field_GetBlock194(void);
extern void Ov002_DrawMissionGaugeTrack(void *surface);
extern void Ov002_UpdatePageStamp(void);

typedef struct {
    void *pSurface;     /* +0 */
    char pad0004[8];
    void *pPending;     /* +0xc */
} Ov002DrawContext;

void Ov002_FlushPendingDraw(void) {
    Ov002DrawContext *ctx = (Ov002DrawContext *)Ov002_Field_GetBlock194();

    if (ctx->pPending == 0) {
        return;
    }

    Ov002_DrawMissionGaugeTrack(ctx->pSurface);
    Ov002_UpdatePageStamp();
    ctx->pPending = 0;
}
