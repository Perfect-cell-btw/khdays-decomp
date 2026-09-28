/* Ov008_PlaceDraggedNode -- Ov008_PlaceDraggedNode: place the dragged node
 * (+0x19b4) at the cursor (+0x64 / +0x66) on the visible page (+0x18);
 * returns 1 when it was placed, 0 without a node or when the cell refuses
 * it.  A summary snapshot is built first.  Any record already in the cell
 * (page slots +0x19c4) is looked up in inventory list 0 together with the
 * node tracked at the cell.  Unless the placement replaced the same item
 * (+0x54), the replaced record's placed count (+0x1bf0) is decremented and
 * mirrored into its inventory item (row refreshed in menu mode 0), the
 * replaced node's cells cleared and the node unlinked before the record is
 * placed again, and the placed record's row counter bumped; the grid surface
 * (+0xac) is queued.  Once every owned copy (GameState 0x810) is placed the
 * drag is reset, state 2 entered and the busy word (+0x30) cleared; the drag
 * is also reset when bKeepDrag is off.  Without a same-item replacement the
 * summary (+0x1f78) is rebuilt, diffed against the snapshot, the row block
 * disabled, the equip panel refreshed and the change set computed (tag 0x48
 * trigger, page-1 mission row when any change word is set).  The snapshot
 * is released, the grid hits rebuilt and widgets 100 / 0x60 hidden.
 * Codegen: the cursor cell index is a local computed first and the page
 * slot is written pCtx->apPageSlot[pCtx->nVisiblePage][nCell] at each of its
 * three uses (no slot pointer local): the page row is then the compiler's
 * own CSE temp and the base / page / index temps take the ROM's registers.
 */

#include "nitro/types.h"

#define GRID_COLS      5
#define WIDGET_HINT_A  100
#define WIDGET_HINT_B  0x60
#define STATE_IDLE     2

typedef struct Ov008Message15Record {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
} Ov008Message15Record;

typedef struct Ov008InventoryItem {
    Ov008Message15Record *pRecord;  /* 0x00 */
    u8  nCount;               /* 0x04 */
    u8  nPlaced;              /* 0x05 */
} Ov008InventoryItem;

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
    int menuMode;             /* 0x0008 */
    u8  pad_000c[0x18 - 0xc];
    u32 nVisiblePage;         /* 0x0018 */
    u8  pad_001c[0x30 - 0x1c];
    int nBusyWord;            /* 0x0030 */
    u8  pad_0034[0x54 - 0x34];
    int bReplacedSame;        /* 0x0054: the cell already held the same item */
    u8  pad_0058[0x64 - 0x58];
    u16 nCursorCol;           /* 0x0064 */
    u16 nCursorRow;           /* 0x0066 */
    u8  pad_0068[0xac - 0x68];
    u8  gridSurface[0x19b4 - 0xac]; /* 0x00ac */
    Ov008Message15Record *pListNode; /* 0x19b4 */
    u8  pad_19b8[0x19c4 - 0x19b8];
    Ov008Message15Record *apPageSlot[3][40]; /* 0x19c4 */
    u8  pad_1ba4[0x1bf0 - 0x1ba4];
    u8  aPlaced[0x1e7c - 0x1bf0]; /* 0x1bf0: placed count per item id */
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
extern void  Ov008_InitRecordContext(Ov008GridSummary *pSummary, void *pHooks);        /* init a summary */
extern void  Ov008_RebuildViewAndCountCells(Ov008GridSummary *pSummary, void *pSlots, void *pList); /* RebuildViewAndCountCells */
extern Ov008InventoryItem *Ov008_FindListObjectByKey(Ov008MenuContext *pCtx, int nList, int nItemId); /* find the inventory item */
extern void *Ov008_FindGridHit(Ov008MenuContext *pCtx, u32 nPage, u32 nCol, u32 nRow); /* Ov008_FindGridHit */
extern int   Ov008_PlaceNodeOnPage(Ov008MenuContext *pCtx, Ov008Message15Record *pRecord, u32 nPage, u32 nCol, u16 nRow); /* place at cell */
extern void  Ov008_RefreshInventoryRow(Ov008MenuContext *pCtx, int nItemId);           /* Ov008_RefreshInventoryRow */
extern void  Ov008_ClearNodeCells(Ov008MenuContext *pCtx, void *pNode);           /* Ov008_ClearNodeCells */
extern void  Ov008_RemoveAndFreeBlock(Ov008MenuContext *pCtx, void *pNode);           /* unlink the node */
extern void  Ov008_BumpRowCounter(Ov008MenuContext *pCtx, int nItemId, char nDelta); /* Ov008_BumpRowCounter */
extern void  func_ov008_02053464(Ov008GridSummary *pSummary);            /* release a summary */
extern void  EnqueueObjGfxCommand(void *pSurface);                                      /* EnqueueObjGfxCommand */
extern char  Ov008_CountGridEntriesForOwner(Ov008MenuContext *pCtx, int nItemId);           /* Ov008_CountGridEntriesForOwner */
extern void  Ov008_ResetGridDrag(Ov008MenuContext *pCtx, int nArg);              /* Ov008_ResetGridDrag */
extern void  Ov008_EnterMenuState(Ov008MenuContext *pCtx, int nState);            /* Ov008_EnterMenuState */
extern void  Ov008_DiffGridSummary(Ov008GridSummary *pNew, Ov008GridSummary *pOld); /* Ov008_DiffGridSummary */
extern void  Ov008_DisableRowBlock(void);                                          /* Ov008_DisableRowBlock */
extern void  Ov008_RefreshEquipPanel(Ov008GridSummary *pSummary);                    /* Ov008_RefreshEquipPanel */
extern int   Ov008_ComputeGridChanges(Ov008GridChanges *pOut, Ov008GridSummary *pOld, Ov008GridSummary *pNew);
extern void  Ov008_TriggerTag48IfState0(void);                                          /* Ov008_TriggerTag48IfState0 */
extern void  Ov008_EnableMissionRowOnPage1(void);                                          /* Ov008_EnableMissionRowOnPage1 */
extern void  Ov008_RebuildGridHits(Ov008MenuContext *pCtx);                        /* Ov008_RebuildGridHits */
extern int   Ov008_GetContext(void);                                          /* Ov008_GetContext */
extern void *Ov008_FindEntryById(int nCtx, int nId);                             /* FindEntryById */
extern void  Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);          /* SetEntrySlotsVisible */

int Ov008_PlaceDraggedNode(Ov008MenuContext *pCtx, int bKeepDrag)
{
    Ov008GridSummary snapshot;
    Ov008GridChanges changes;
    Ov008InventoryItem *pItem;
    void *pNode;
    Ov008Message15Record *pReplaced;
    int nCell;
    int nItemId;
    int nCtx;

    pItem = 0;
    pNode = 0;
    pReplaced = 0;
    if (pCtx->pListNode == 0) {
        return 0;
    }
    Ov008_InitRecordContext(&snapshot, pCtx->summaryHooks);
    Ov008_RebuildViewAndCountCells(&snapshot, pCtx->apPageSlot, pCtx->trackedNodeList);
    nCell = pCtx->nCursorCol + pCtx->nCursorRow * GRID_COLS;
    if (pCtx->apPageSlot[pCtx->nVisiblePage][nCell] != 0) {
        pReplaced = pCtx->apPageSlot[pCtx->nVisiblePage][nCell];
        pItem = Ov008_FindListObjectByKey(pCtx, 0, pCtx->apPageSlot[pCtx->nVisiblePage][nCell]->nItemId);
        pNode = Ov008_FindGridHit(pCtx, pCtx->nVisiblePage, pCtx->nCursorCol, pCtx->nCursorRow);
    }
    if (Ov008_PlaceNodeOnPage(pCtx, pCtx->pListNode, pCtx->nVisiblePage, pCtx->nCursorCol, pCtx->nCursorRow) != 0) {
        if (pCtx->bReplacedSame == 0) {
            if (pReplaced != 0) {
                pCtx->aPlaced[pReplaced->nItemId]--;
            }
            if (pItem != 0) {
                pItem->nPlaced = pCtx->aPlaced[pItem->pRecord->nItemId];
                if (pCtx->menuMode == 0) {
                    Ov008_RefreshInventoryRow(pCtx, pItem->pRecord->nItemId);
                }
            }
            if (pNode != 0) {
                Ov008_ClearNodeCells(pCtx, pNode);
                Ov008_RemoveAndFreeBlock(pCtx, pNode);
                Ov008_PlaceNodeOnPage(pCtx, pCtx->pListNode, pCtx->nVisiblePage, pCtx->nCursorCol, pCtx->nCursorRow);
                Ov008_BumpRowCounter(pCtx, pCtx->pListNode->nItemId, 1);
            }
            Ov008_BumpRowCounter(pCtx, pCtx->pListNode->nItemId, 1);
        }
    } else {
        func_ov008_02053464(&snapshot);
        return 0;
    }
    if (pCtx->bReplacedSame == 0) {
        EnqueueObjGfxCommand(pCtx->gridSurface);
    }
    nItemId = pCtx->pListNode->nItemId;
    if ((u32)Ov008_CountGridEntriesForOwner(pCtx, nItemId) >= data_0204be18->aItemCount[nItemId]) {
        Ov008_ResetGridDrag(pCtx, 0);
        Ov008_EnterMenuState(pCtx, STATE_IDLE);
        pCtx->nBusyWord = 0;
    }
    if (bKeepDrag == 0) {
        Ov008_ResetGridDrag(pCtx, 0);
    }
    if (pCtx->bReplacedSame == 0) {
        Ov008_RebuildViewAndCountCells(&pCtx->summary, pCtx->apPageSlot, pCtx->trackedNodeList);
        Ov008_DiffGridSummary(&pCtx->summary, &snapshot);
        Ov008_DisableRowBlock();
        Ov008_RefreshEquipPanel(&pCtx->summary);
        if (Ov008_ComputeGridChanges(&changes, &snapshot, &pCtx->summary) != 0) {
            Ov008_TriggerTag48IfState0();
        }
        if (changes.aChanged[0] != 0 || changes.aChanged[1] != 0 || changes.aChanged[2] != 0 || changes.aChanged[3] != 0) {
            Ov008_EnableMissionRowOnPage1();
        }
    }
    func_ov008_02053464(&snapshot);
    Ov008_RebuildGridHits(pCtx);
    nCtx = Ov008_GetContext();
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, WIDGET_HINT_A), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, WIDGET_HINT_B), 0);
    return 1;
}
