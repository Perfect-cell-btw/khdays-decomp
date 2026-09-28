/* Repaints the whole panel row list. The shared block is copied over the panel's own first, then
 * every row up to wCount0112 is drawn in the mode the first gauge dictates - 2 only when that gauge
 * is both active and mid-phase, 0 otherwise - and the rows between there and wRowsFilled are drawn
 * in mode 1. The bulk call that follows is asked for wRowsPending more rows, cut back so the total
 * never passes wRowLimit. Finally the scroll thumb is refreshed from wScrollThumb while a prompt is
 * pending and from the row count otherwise, and bit 3 of bStateFlags is raised so the tick pushes
 * the result. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 wField0000;
    u16 wCount;                         /* +0x02 of the record */
} Ov002RecordHead;

typedef struct {
    int aHandles[4];                    /* +0x00 */
    int aBlocks[4];                     /* +0x10 */
    u8 pad0020[8];
    u8 bStateFlags;                     /* +0x28 */
    u8 pad0029[3];
    int bPromptOpen;                    /* +0x2c */
    u8 pad0030[0x4c];
    int bGaugeActive;                   /* +0x7c */
    int nGaugePhase;                    /* +0x80 */
    u8 pad0084[0x70];
    u16 wLimit00f4;                     /* +0xf4 */
    u16 wDrawn00f6;                     /* +0xf6 */
    u8 pad00f8[2];
    u16 wPending00fa;                   /* +0xfa */
    u8 pad00fc[0x14];
    Ov002RecordHead rec0110;            /* +0x110; its wCount is +0x112 */
    u8 pad0114[0x64];
    int bPromptPending;                 /* +0x178 */
    u8 pad017c[6];
    u16 wPromptCount0182;               /* +0x182 */
} Ov002SceneCtx;

extern Ov002SceneCtx *data_ov002_0207f618;

extern void MIi_CpuCopyFast(void *pSrc, void *pDst, int nSize);
extern void Ov002_DrawGaugeTweenCell(int nHandle, int nCell, int nMode);
extern void Ov002_DrawGaugeSpan(int nHandle, int nCell, int nCount, int nA, int nB,
                                int nC, int nD);
extern void Ov002_DrawPromptMarker(int nCount);

void Ov002_RepaintPanelRows(void) {
    Ov002SceneCtx *ctx = data_ov002_0207f618;
    int i;
    int nMode;
    int nCount;
    Ov002RecordHead *pRec = &ctx->rec0110;

    MIi_CpuCopyFast((void *)ctx->aBlocks[0], (void *)ctx->aHandles[0], 0x140);
    i = 0;
    nMode = (ctx->bGaugeActive != 0 && ctx->nGaugePhase != 0) ? 2 : 0;

    for (i = 0; i < pRec->wCount; i++) {
        Ov002_DrawGaugeTweenCell(ctx->aHandles[0], i, nMode);
    }
    for (; i < ctx->wDrawn00f6; i++) {
        Ov002_DrawGaugeTweenCell(ctx->aHandles[0], i, 1);
    }

    nCount = ctx->wPending00fa;
    if (nCount + ctx->wDrawn00f6 > ctx->wLimit00f4) {
        nCount = ctx->wLimit00f4 - ctx->wDrawn00f6;
    }
    Ov002_DrawGaugeSpan(ctx->aHandles[0], i, nCount, 6, 0x4d, 1, 0);

    if (ctx->bPromptPending != 0) {
        Ov002_DrawPromptMarker(ctx->wPromptCount0182);
    } else if (ctx->bPromptOpen != 0) {
        Ov002_DrawPromptMarker(pRec->wCount);
    }
    ctx->bStateFlags = ctx->bStateFlags | 8;
}
