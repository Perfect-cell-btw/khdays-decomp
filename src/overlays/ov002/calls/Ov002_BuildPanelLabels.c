/*
 * Ov002_BuildPanelLabels - build the panel's text surface and draw the four
 * entry labels onto it.
 *
 * The surface is set up from a template config with the item's VRAM target and
 * the context's own pixel block, then the cell handles it hands back are kept:
 * the first from the surface itself and the next three from cell zero, plus one
 * from cell one that the teardown selects at the end.
 *
 * Each of the four entries names a string id. A negative id ends the run early.
 * With either of the two mode bits set, ids 0x53 and 0x54 are swapped for 0x75
 * and 0x76 - the alternative wording - and everything else is looked up as it
 * stands. Each label is drawn twice, one pixel apart and in two different
 * modes, which is the drop shadow; a line wider than 0x4f shifts both by one.
 *
 * THUMB.
 */

typedef unsigned char u8;

typedef struct {
    char pad0000[0x18];
    int nVramTarget;                    /* +0x18 */
    char pad001c[4];
    void *pPixels;                      /* +0x20 */
    char pad0024[4];
} Ov002SurfaceCfg;

typedef struct {
    char pad0000[0x24];
    char aPixels[0x20];                 /* +0x024 */
    int bBuilt;                         /* +0x044 */
    char pad0048[0x24];
    char aSurface[0x20];                /* +0x06c */
    int pFont;                          /* +0x08c */
    int pFontData;                      /* +0x090 */
    char pad0094[0x14];
    void *apCells[5];                   /* +0x0a8 */
    char pad00bc[0xc4];
    short *pEntryIds;                   /* +0x180 */
} Ov002PanelCtx;

extern Ov002PanelCtx *data_ov002_0207f614;
extern u8 data_0204c240;
extern Ov002SurfaceCfg data_ov002_0207dc38;
extern int data_ov002_0207e8dc;
extern int data_ov002_0207e8f4;

extern void Resource_BindByName(void *pField, const void *pTable);
extern void FreeFieldAt8(void *pField);
extern void TileSurface_InitAndUpload4bpp(void *pSurface, const Ov002SurfaceCfg *pCfg);
extern void *TileSurface_AddCanvas(void *pSurface, int nCell);
extern void TileSurface_SetCurrentItem(void *pSurface, void *pItem, int a);
extern void Text_DrawDirectional_2(void *pSurface, int nX, int nY, int nMode,
                          unsigned int nFlags, int *pRec);
extern void *Obj_GetWord18(void *pSurface);
extern int NNSi_G2dFontGetStringWidth(int a, int b, int *pRec, int d);
extern void Obj_InvokeInnerVtable4(void *pSurface);

extern int Ov002_Hud_GetBlock24(void);
extern void Ov002_InitResourceRecord(void *pThis, void *pTable);
extern void Ov002_FreeResourceRecordBuffer(void *pThis);
extern int *Ov002_GetVarRecordByIndex(void *pThis, int nId);
extern int Ov002_GetItemResource(int nId);
extern void Ov002_SelectEntry(int nId);
extern void Ov002_PickTextFitting80(void *pSurface, int a, void *b, int *pRec);

void Ov002_BuildPanelLabels(void)
{
    Ov002PanelCtx *ctx;
    Ov002PanelCtx *pWalk;
    int i;
    int nId;
    int nFont;
    int nOffset;
    int nShift;
    void *pSurface;
    int *pRec;
    Ov002SurfaceCfg cfg;
    int aRecords[3];
    int aBind[3];

    ctx = data_ov002_0207f614;
    pWalk = ctx;
    cfg = data_ov002_0207dc38;
    Resource_BindByName(aBind, &data_ov002_0207e8dc);
    nFont = Ov002_Hud_GetBlock24();
    Ov002_InitResourceRecord(aRecords, &data_ov002_0207e8f4);
    cfg.nVramTarget = Ov002_GetItemResource(9);
    cfg.pPixels = ctx->aPixels;
    TileSurface_InitAndUpload4bpp(ctx->aSurface, &cfg);
    Obj_InvokeInnerVtable4(ctx->aSurface);
    ctx->apCells[0] = Obj_GetWord18(ctx->aSurface);

    /* One cell handle per entry lives at +0xa8, four bytes apart, so the
       cursor walks the context itself. The first came from the surface; the
       other three are cell zero handed out again. */
    i = 1;
    pWalk = (Ov002PanelCtx *)((char *)ctx + 4);
    for (; i < 4; i++) {
        pWalk->apCells[0] = TileSurface_AddCanvas(ctx->aSurface, 0);
        pWalk = (Ov002PanelCtx *)((char *)pWalk + 4);
    }
    ctx->apCells[4] = TileSurface_AddCanvas(ctx->aSurface, 1);

    i = 0;
    nOffset = 0;
    pWalk = ctx;
    pSurface = ctx->aSurface;
    do {
        nId = *(short *)((char *)ctx->pEntryIds + nOffset);
        if (nId < 0) {
            break;
        }
        if ((data_0204c240 & 4) != 0 || (data_0204c240 & 8) != 0) {
            switch (nId) {
            case 0x53:
                pRec = Ov002_GetVarRecordByIndex(aRecords, 0x75);
                break;
            case 0x54:
                pRec = Ov002_GetVarRecordByIndex(aRecords, 0x76);
                break;
            default:
                pRec = Ov002_GetVarRecordByIndex(aRecords, nId);
                break;
            }
        } else {
            pRec = Ov002_GetVarRecordByIndex(aRecords, nId);
        }
        if (pRec != 0) {
            nShift = 0;
            TileSurface_SetCurrentItem(pSurface, pWalk->apCells[0], nShift);
            Ov002_PickTextFitting80(pSurface, nFont, aBind, pRec);
            if (NNSi_G2dFontGetStringWidth(ctx->pFont, ctx->pFontData, pRec, nShift) >= 0x50) {
                nShift = 1;
            }
            Text_DrawDirectional_2(pSurface, nShift + 0x50, 1, 1, 0x821, pRec);
            Text_DrawDirectional_2(pSurface, nShift + 0x4f, 0, 2, 0x821, pRec);
        }
        nOffset += 2;
        pWalk = (Ov002PanelCtx *)((char *)pWalk + 4);
        i++;
    } while (i < 4);

    Ov002_FreeResourceRecordBuffer(aRecords);
    TileSurface_SetCurrentItem(ctx->aSurface, ctx->apCells[4], 0);
    ctx->bBuilt = 1;
    Ov002_SelectEntry(9);
    FreeFieldAt8(aBind);
}
