/* Builds the four gauges from a setup block. A shared 0xc0-byte block is copied and a second one
 * allocated first. Then, per gauge, the requested count is clamped to the cap, the count pair is
 * seeded with the total and a zero, and a gauge that asks for anything at all gets its own block
 * copied and a private allocation filled from it, which raises that gauge's bit in bStateFlags so
 * the tick repaints it. Every gauge, empty or not, is handed to the shared setter with mode 7. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 wA;
    u16 wB;
} Ov002CountPair;

typedef struct {
    int nField0000;
    int nField0004;
    int nSize;
} Ov002GaugeRow;

typedef struct {
    int aHandles[4];                    /* +0x00 */
    int aBlocks[4];                     /* +0x10 */
    int nSharedBlock;                   /* +0x20 */
    int nSharedCopy;                    /* +0x24 */
    u8 bStateFlags;                     /* +0x28 */
    u8 pad0029[0xa3];
    Ov002CountPair aCounts[4];          /* +0xcc */
} Ov002SceneCtx;

typedef struct {
    u16 aTotals[4];                     /* +0x00 */
    u16 aCaps[4];                       /* +0x08 */
    u8 pad0010[0xc];
    int nSource;                        /* +0x1c */
} Ov002GaugeSetup;

extern Ov002SceneCtx *data_ov002_0207f618;
extern Ov002GaugeRow data_ov002_0207ddfc[];

extern void Ov002_DuplicateBlock(void *pDst, void *pSrc, int nSize);
extern void *NNSi_FndAllocFromDefaultExpHeap(int nSize);
extern void MIi_CpuCopyFast(void *pSrc, void *pDst, int nSize);
extern void Ov002_SetGaugeValue(int nIndex, int nValue, int nMode, int nFlagA,
                                int nFlagB);

void Ov002_InitGauges(Ov002GaugeSetup *pSetup) {
    Ov002SceneCtx *ctx = data_ov002_0207f618;
    u8 *pDirty;
    int nSource = pSetup->nSource;
    int *pSurface;
    int i;
    Ov002GaugeRow *pRow;
    void *pBuffer;

    Ov002_DuplicateBlock(&ctx->nSharedCopy, (void *)(nSource + 0x5e0), 0xc0);
    ctx->nSharedBlock = (int)NNSi_FndAllocFromDefaultExpHeap(0xc0);
    pSurface = &ctx->aBlocks[0];
    i = 0;
    pDirty = &ctx->bStateFlags;
    pRow = data_ov002_0207ddfc;
    do {
        if (pSetup->aCaps[0] > pSetup->aTotals[0]) {
            pSetup->aCaps[0] = pSetup->aTotals[0];
        }
        ctx->aCounts[0].wA = pSetup->aTotals[0];
        ctx->aCounts[0].wB = 0;
        if (pSetup->aTotals[0] != 0) {
            Ov002_DuplicateBlock(pSurface, (void *)(nSource + pRow->nField0000),
                                pRow->nField0004);
            pBuffer = NNSi_FndAllocFromDefaultExpHeap(pRow->nField0004);
            ctx->aHandles[0] = (int)pBuffer;
            MIi_CpuCopyFast((void *)ctx->aBlocks[0], (void *)ctx->aHandles[0],
                            pRow->nField0004);
            *pDirty |= 1 << (i + 3);
        }
        Ov002_SetGaugeValue(i, pSetup->aCaps[0], 7, 0, 1);
        i++;
        pSetup = (Ov002GaugeSetup *)((u16 *)pSetup + 1);
        ctx = (Ov002SceneCtx *)((int *)ctx + 1);
        pSurface++;
        pRow++;
    } while (i < 4);
}
