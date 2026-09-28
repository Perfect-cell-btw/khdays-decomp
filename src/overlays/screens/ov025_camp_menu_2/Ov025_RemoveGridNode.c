/* Ov025_RemoveGridNode -- Ov008_RemoveGridNode: take the entry out of page
 * slot (nPage, nCol, nRow).  Nothing (0) when the slot is empty.  Otherwise a
 * summary snapshot is built (hooks +0x2090; slots +0x19c4, node list
 * +0x1e7c); unless bSilent or the grid busy word (+0x8) is set, the entry's
 * row counter (+0x14) is bumped down and the grid surface (+0xac) queued;
 * on the visible page the display cell is deactivated; the slot is cleared,
 * the node found there (Ov008_FindGridHit) has its cells cleared and is
 * unlinked (020609e4).  Unless bSilent the context summary (+0x1f78) is
 * rebuilt and diffed against the snapshot, the change set computed (tag 0x48
 * trigger, page-1 mission row when any change word is set), the row block
 * disabled and the equip panel refreshed.  The snapshot is released and the
 * grid hits rebuilt; returns 1.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define PAGE_COLS 5

typedef struct Ov008ShapeEntry {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
} Ov008ShapeEntry;

typedef struct Ov008GridDisplayCell {
    int isActive;             /* 0x00 */
    u8  pad_04[0x28 - 4];
} Ov008GridDisplayCell;

typedef struct Ov008GridSummary {
    u8 pad[0x100];
} Ov008GridSummary;

typedef struct Ov008GridChanges {
    u8  pad_00[8];
    int aChanged[4];          /* 0x08 */
    u8  pad_18[0xb8 - 0x18];
} Ov008GridChanges;

typedef struct Ov008MenuContext {
    u8  pad_0000[8];
    int nBusy;                /* 0x0008 */
    u8  pad_000c[0x18 - 0xc];
    u32 nVisiblePage;         /* 0x0018 */
    u8  pad_001c[0xac - 0x1c];
    u8  gridSurface[0x10a0 - 0xac];     /* 0x00ac */
    Ov008GridDisplayCell gridDisplayCells[8][PAGE_COLS]; /* 0x10a0 */
    u8  pad_16e0[0x19c4 - 0x16e0];
    Ov008ShapeEntry *apPageSlot[3][8 * PAGE_COLS]; /* 0x19c4 */
    u8  pad_1ba4[0x1e7c - 0x1ba4];
    u8  trackedNodeList[12];            /* 0x1e7c */
    u8  pad_1e88[0x1f78 - 0x1e88];
    Ov008GridSummary summary;           /* 0x1f78 */
    u8  pad_2078[0x2090 - 0x2078];
    u8  summaryHooks[8];                /* 0x2090 */
} Ov008MenuContext;

extern void Ov025_InitRecordContext(Ov008GridSummary *pSummary, void *pHooks);        /* init a summary */
extern void Ov025_RebuildViewAndCountCells(Ov008GridSummary *pSummary, void *pSlots, void *pList); /* RebuildViewAndCountCells */
extern void Ov025_AdjustAndSyncSlot(Ov008MenuContext *pCtx, int nItemId, char nDelta); /* Ov008_BumpRowCounter */
extern void EnqueueObjGfxCommand(void *pSurface);                                        /* EnqueueObjGfxCommand */
extern void *Ov025_FindGridHit(Ov008MenuContext *pCtx, u32 nPage, u32 nCol, u32 nRow); /* Ov008_FindGridHit */
extern void Ov025_ClearNodeCells(Ov008MenuContext *pCtx, void *pNode);             /* Ov008_ClearNodeCells */
extern void Ov025_RemoveAndFreeBlock(Ov008MenuContext *pCtx, void *pNode);             /* unlink the node */
extern void Ov025_DiffGridSummary(Ov008GridSummary *pNew, Ov008GridSummary *pOld);  /* Ov008_DiffGridSummary */
extern int  Ov025_ComputeGridChanges(Ov008GridChanges *pOut, Ov008GridSummary *pOld, Ov008GridSummary *pNew);
extern void Ov025_TriggerTag48IfState0(void);                                            /* Ov008_TriggerTag48IfState0 */
extern void Ov025_TriggerTag47IfState1(void);                                            /* Ov008_EnableMissionRowOnPage1 */
extern void Ov025_ClearTagRange(void);                                            /* Ov008_DisableRowBlock */
extern void Ov025_RefreshStatusPage(Ov008GridSummary *pSummary);                      /* Ov008_RefreshEquipPanel */
extern void func_ov025_02087254(Ov008GridSummary *pSummary);              /* release a summary */
extern void Ov025_RebuildGridHits(Ov008MenuContext *pCtx);                          /* Ov008_RebuildGridHits */

int Ov025_RemoveGridNode(Ov008MenuContext *pCtx, u32 nPage, u32 nCol, u32 nRow, int bSilent)
{
    Ov008GridSummary snapshot;
    Ov008GridChanges changes;
    Ov008ShapeEntry **pSlot;
    void *pNode;

    pSlot = &pCtx->apPageSlot[nPage][nRow * PAGE_COLS + nCol];
    if (*pSlot == 0) {
        return 0;
    }
    Ov025_InitRecordContext(&snapshot, pCtx->summaryHooks);
    Ov025_RebuildViewAndCountCells(&snapshot, pCtx->apPageSlot, pCtx->trackedNodeList);
    if (bSilent == 0 && pCtx->nBusy == 0) {
        Ov025_AdjustAndSyncSlot(pCtx, (*pSlot)->nItemId, -1);
        EnqueueObjGfxCommand(pCtx->gridSurface);
    }
    if (nPage == pCtx->nVisiblePage) {
        pCtx->gridDisplayCells[nRow][nCol].isActive = 0;
    }
    *pSlot = 0;
    pNode = Ov025_FindGridHit(pCtx, nPage, nCol, nRow);
    if (pNode != 0) {
        Ov025_ClearNodeCells(pCtx, pNode);
        Ov025_RemoveAndFreeBlock(pCtx, pNode);
    }
    if (bSilent == 0) {
        Ov025_RebuildViewAndCountCells(&pCtx->summary, pCtx->apPageSlot, pCtx->trackedNodeList);
        Ov025_DiffGridSummary(&pCtx->summary, &snapshot);
        if (Ov025_ComputeGridChanges(&changes, &snapshot, &pCtx->summary) != 0) {
            Ov025_TriggerTag48IfState0();
        }
        if (changes.aChanged[0] != 0 || changes.aChanged[1] != 0 || changes.aChanged[2] != 0 || changes.aChanged[3] != 0) {
            Ov025_TriggerTag47IfState1();
        }
        Ov025_ClearTagRange();
        Ov025_RefreshStatusPage(&pCtx->summary);
    }
    func_ov025_02087254(&snapshot);
    Ov025_RebuildGridHits(pCtx);
    return 1;
}
