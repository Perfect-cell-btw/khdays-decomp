/* Ov025_DropLiftedNode -- Ov008_DropLiftedNode: drop the lifted node
 * (+0x19b4) at the cursor (+0x64 / +0x66) on the visible page (+0x18).  A
 * summary snapshot is built first.  The node found at the drag home (+0x68,
 * +0x6c / +0x6e) must accept the move to the cursor minus the node's anchor
 * offset (+0x28 / +0x29) and the lifted record must fit at the cursor; then
 * both the target and the home cells are cleaned, the record placed at the
 * cursor with its row counter bumped, and every lifted cell (+0x19b8) placed
 * at the cursor plus its offset likewise.  An unplaced record (+0x24 < 0)
 * that is not category 6 arms the hold count (+0x44) and, while more copies
 * are owned (GameState 0x810) than are on the grid and no scroll (+0x2c) is
 * running, sets the busy words (+0x30 / +0x34) and steps the cursor; any
 * other case resets the drag, an already placed record also clearing the
 * tracked cells.  The grid hits are rebuilt, the surface (+0xac) queued,
 * the summary (+0x1f78) rebuilt, the row block disabled, the equip panel
 * refreshed and the change set against the snapshot computed (tag 0x48
 * trigger, page-1 mission row when any change word is set).  Returns 1 on a
 * completed drop, 0 otherwise; the snapshot is released either way.
 * Codegen: both inner conditions are written with the reset case first.
 */

#include "nitro/types.h"

#define CATEGORY_FIXED 6

typedef struct Ov008Message15Record {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
    int nCategory;            /* 0x18 */
    u8  pad_1c[8];
    int nPlacedSlot;          /* 0x24: -1 = not placed */
    u8  nOffsetCol;           /* 0x28 */
    u8  nOffsetRow;           /* 0x29 */
} Ov008Message15Record;

typedef struct Ov008LiftedCell {
    Ov008Message15Record *pRecord; /* 0x00 */
    int nColOffset;           /* 0x04: from the anchor */
    int nRowOffset;           /* 0x08 */
    u8  pad_0c[0x18 - 0xc];
} Ov008LiftedCell;

typedef struct Ov008GridSummary {
    u8 pad[0x100];
} Ov008GridSummary;

typedef struct Ov008GridChanges {
    u8  pad_00[8];
    int aChanged[4];          /* 0x08 */
    u8  pad_18[0xb8 - 0x18];
} Ov008GridChanges;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x18];
    u32 nVisiblePage;         /* 0x0018 */
    u8  pad_001c[0x2c - 0x1c];
    int bScroll;              /* 0x002c */
    int nBusyWord;            /* 0x0030 */
    int bHolding;           /* 0x0034: still holding a copy to place */
    u8  pad_0038[0x44 - 0x38];
    int nHoldCount;           /* 0x0044 */
    u8  pad_0048[0x64 - 0x48];
    u16 nCursorCol;           /* 0x0064 */
    u16 nCursorRow;           /* 0x0066 */
    u32 nDragPage;            /* 0x0068: home page of the lifted node */
    u16 nHomeCol;             /* 0x006c */
    u16 nHomeRow;             /* 0x006e */
    u8  pad_0070[0xac - 0x70];
    u8  gridSurface[0x19b4 - 0xac]; /* 0x00ac */
    Ov008Message15Record *pListNode; /* 0x19b4 */
    u8  liftedList[0xc];      /* 0x19b8 */
    u8  apPageSlot[0x1e7c - 0x19c4]; /* 0x19c4 */
    u8  trackedNodeList[0xc]; /* 0x1e7c */
    u8  pad_1e88[0x1f78 - 0x1e88];
    Ov008GridSummary summary; /* 0x1f78 */
    u8  pad_2078[0x2090 - 0x2078];
    u8  summaryHooks[8];      /* 0x2090 */
} Ov008MenuContext;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];     /* 0x810 */
} GameState;

extern GameState *data_0204be18;
extern void  Ov025_InitRecordContext(Ov008GridSummary *pSummary, void *pHooks);        /* init a summary */
extern void  Ov025_RebuildViewAndCountCells(Ov008GridSummary *pSummary, void *pSlots, void *pList); /* RebuildViewAndCountCells */
extern void *Ov025_FindGridHit(Ov008MenuContext *pCtx, u32 nPage, u32 nCol, u32 nRow); /* Ov008_FindGridHit */
extern int   Ov025_PlaceNodeShape(Ov008MenuContext *pCtx, void *pNode, u32 nPage, int nCol, int nRow, int nArg); /* move the node */
extern int   Ov025_CanPlaceRecord(Ov008MenuContext *pCtx, Ov008Message15Record *pRecord, u32 nPage, u32 nCol, u32 nRow, int nArg); /* record fits */
extern void  Ov025_ProcessAndCleanup(Ov008MenuContext *pCtx, unsigned int nPage, u32 nCol, u32 nRow); /* Ov008_ProcessAndCleanup */
extern int   Ov025_PlaceNodeOnPage(Ov008MenuContext *pCtx, Ov008Message15Record *pRecord, u32 nPage, u32 nCol, u16 nRow); /* place at cell */
extern void  Ov025_AdjustAndSyncSlot(Ov008MenuContext *pCtx, int nItemId, char nDelta); /* Ov008_BumpRowCounter */
extern Ov008LiftedCell *NNS_FndGetNextListObject(void *pList, void *pObject);
extern void  Ov025_ResetGridDrag(Ov008MenuContext *pCtx, int nArg);              /* Ov008_ResetGridDrag */
extern void  Ov025_ClearTrackedGridCells(Ov008MenuContext *pCtx);                        /* Ov008_ClearTrackedGridCells */
extern char  Ov025_CountGridEntriesForOwner(Ov008MenuContext *pCtx, int nItemId);           /* Ov008_CountGridEntriesForOwner */
extern int   Ov025_MoveGridCursor(Ov008MenuContext *pCtx, int nColumn, int nRow, int nStep); /* move the cursor */
extern void  Ov025_RebuildGridHits(Ov008MenuContext *pCtx);                        /* Ov008_RebuildGridHits */
extern void  EnqueueObjGfxCommand(void *pSurface);                                      /* EnqueueObjGfxCommand */
extern void  Ov025_ClearTagRange(void);                                          /* Ov008_DisableRowBlock */
extern void  Ov025_RefreshStatusPage(Ov008GridSummary *pSummary);                    /* Ov008_RefreshEquipPanel */
extern int   Ov025_ComputeGridChanges(Ov008GridChanges *pOut, Ov008GridSummary *pOld, Ov008GridSummary *pNew);
extern void  Ov025_TriggerTag48IfState0(void);                                          /* Ov008_TriggerTag48IfState0 */
extern void  Ov025_TriggerTag47IfState1(void);                                          /* Ov008_EnableMissionRowOnPage1 */
extern void  func_ov025_02087254(Ov008GridSummary *pSummary);            /* release a summary */

int Ov025_DropLiftedNode(Ov008MenuContext *pCtx)
{
    Ov008GridSummary snapshot;
    Ov008GridChanges changes;
    int bDone;
    int nLeft;
    int nTop;
    void *pNode;
    Ov008LiftedCell *pCell;
    int nItemId;

    bDone = 0;
    Ov025_InitRecordContext(&snapshot, pCtx->summaryHooks);
    Ov025_RebuildViewAndCountCells(&snapshot, pCtx->apPageSlot, pCtx->trackedNodeList);
    nLeft = pCtx->nCursorCol - pCtx->pListNode->nOffsetCol;
    nTop = pCtx->nCursorRow - pCtx->pListNode->nOffsetRow;
    pNode = Ov025_FindGridHit(pCtx, pCtx->nDragPage, pCtx->nHomeCol, pCtx->nHomeRow);
    if (pNode == 0 || Ov025_PlaceNodeShape(pCtx, pNode, pCtx->nVisiblePage, nLeft, nTop, 1) != 0) {
        if (Ov025_CanPlaceRecord(pCtx, pCtx->pListNode, pCtx->nVisiblePage, pCtx->nCursorCol, pCtx->nCursorRow, 0) != 0) {
            Ov025_ProcessAndCleanup(pCtx, (u16)pCtx->nVisiblePage, pCtx->nCursorCol, pCtx->nCursorRow);
            Ov025_ProcessAndCleanup(pCtx, (u16)pCtx->nDragPage, pCtx->nHomeCol, pCtx->nHomeRow);
            Ov025_PlaceNodeOnPage(pCtx, pCtx->pListNode, pCtx->nVisiblePage, pCtx->nCursorCol, pCtx->nCursorRow);
            Ov025_AdjustAndSyncSlot(pCtx, pCtx->pListNode->nItemId, 1);
            for (pCell = NNS_FndGetNextListObject(pCtx->liftedList, 0); pCell != 0;
                 pCell = NNS_FndGetNextListObject(pCtx->liftedList, pCell)) {
                Ov025_PlaceNodeOnPage(pCtx, pCell->pRecord, pCtx->nVisiblePage, (u16)(pCtx->nCursorCol + pCell->nColOffset), pCtx->nCursorRow + pCell->nRowOffset);
                Ov025_AdjustAndSyncSlot(pCtx, pCell->pRecord->nItemId, 1);
            }
            if (pCtx->pListNode->nPlacedSlot >= 0 || pCtx->pListNode->nCategory == CATEGORY_FIXED) {
                Ov025_ResetGridDrag(pCtx, 0);
                Ov025_ClearTrackedGridCells(pCtx);
            } else {
                pCtx->nHoldCount = 1;
                nItemId = pCtx->pListNode->nItemId;
                if ((u32)Ov025_CountGridEntriesForOwner(pCtx, nItemId) >= data_0204be18->aItemCount[nItemId] || pCtx->bScroll != 0) {
                    Ov025_ResetGridDrag(pCtx, 0);
                } else {
                    pCtx->bHolding = 1;
                    pCtx->nBusyWord = 1;
                    Ov025_MoveGridCursor(pCtx, pCtx->nCursorCol, pCtx->nCursorRow, 1);
                }
            }
            Ov025_RebuildGridHits(pCtx);
            EnqueueObjGfxCommand(pCtx->gridSurface);
            Ov025_RebuildViewAndCountCells(&pCtx->summary, pCtx->apPageSlot, pCtx->trackedNodeList);
            Ov025_ClearTagRange();
            Ov025_RefreshStatusPage(&pCtx->summary);
            if (Ov025_ComputeGridChanges(&changes, &snapshot, &pCtx->summary) != 0) {
                Ov025_TriggerTag48IfState0();
            }
            if (changes.aChanged[0] != 0 || changes.aChanged[1] != 0 || changes.aChanged[2] != 0 || changes.aChanged[3] != 0) {
                Ov025_TriggerTag47IfState1();
            }
            bDone = 1;
        }
    }
    func_ov025_02087254(&snapshot);
    return bDone;
}
