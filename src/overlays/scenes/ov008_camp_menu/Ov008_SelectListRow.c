/* Ov008_SelectListRow -- Ov008_SelectListRow: make list row nRow the selected
 * row (+0x9c) of the inventory list.  The row is first brought into the
 * eight-row window (Ov008_ScrollMenuRowsTo over the scroll row +0x74 with
 * the page count +0x78, track 0x7f); a row outside the list answers 0.  The
 * row's item id is flagged in the bitset.  When the window did not move the
 * eight visible rows' widgets are refreshed: row widget 400 + i shows the
 * item with its bitset state as frame (hidden while game flag 0x37c9 + id is
 * set) and widget 500 + i follows the item's placed-copies byte (+5);
 * otherwise the rows are rebuilt from the new first row (0205e2e0).  Finally
 * the row is highlighted relative to the scroll row.  Returns 1.
 */

#include "nitro/types.h"
#include "game/engine.h"

#define VISIBLE_ROWS  8
#define TRACK_END     0x7f
#define ROW_WIDGET_A  400
#define ROW_WIDGET_B  500
#define FLAG_ITEM_HIDDEN 0x37c9

typedef struct Ov008Message15Record {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
} Ov008Message15Record;

typedef struct Ov008InventoryItem {
    Ov008Message15Record *pRecord;  /* 0x00 */
    u8  nCount;               /* 0x04: copies owned */
    u8  nPlaced;              /* 0x05: copies on the grid */
} Ov008InventoryItem;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x70];
    int nRowBase;             /* 0x0070 */
    int nScrollRow;           /* 0x0074 */
    int nPageCount;           /* 0x0078 */
    u8  pad_007c[0x9c - 0x7c];
    int nSelectedRow;         /* 0x009c */
    u8  pad_00a0[0x300 - 0xa0];
    void *pList;              /* 0x0300: current inventory list */
} Ov008MenuContext;

extern int  Ov008_GetContext(void);                                    /* Ov008_GetContext */
extern int  Ov008_ScrollMenuRowsTo(Ov008MenuContext *pCtx, int nRow, int nFirst, int nTotal, int nTrackEnd, int nVisible); /* Ov008_ScrollMenuRowsTo */
extern Ov008InventoryItem *NNS_FndGetNthListObject(void *pList, int nIndex);        /* List_GetNthObject */
extern void Ov008_SetBitInBitset(Ov008MenuContext *pCtx, int nItemId);     /* Ov008_SetBitInBitset */
extern void Ov008_RefreshInventoryRows(Ov008MenuContext *pCtx, int nRowBase, int nFirst); /* rebuild the visible rows */
extern void *Ov008_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);    /* SetEntrySlotsVisible */
extern int  Ov008_TestBitInBitset(Ov008MenuContext *pCtx, int nItemId);     /* TestBitInBitset */
extern void Ov008_ReleaseTwoSlotsEx(int nCtx, void *pEntry, int nFrame);      /* Ov008_ReleaseTwoSlotsEx */
extern Ov008InventoryItem *NNS_FndGetNextListObject(void *pList, void *pObject);
extern void Ov008_HighlightListRow(Ov008MenuContext *pCtx, int nRow);        /* highlight a visible row */

int Ov008_SelectListRow(Ov008MenuContext *pCtx, int nRow)
{
    int i;
    int nCtx;
    int nFirst;
    Ov008InventoryItem *pItem;

    i = 0;
    nCtx = Ov008_GetContext();
    nFirst = Ov008_ScrollMenuRowsTo(pCtx, nRow, pCtx->nScrollRow, pCtx->nPageCount, TRACK_END, VISIBLE_ROWS);
    if (nFirst < 0) {
        return 0;
    }
    pCtx->nSelectedRow = nRow;
    pItem = NNS_FndGetNthListObject(pCtx->pList, (u16)nRow);
    if (pItem != 0) {
        Ov008_SetBitInBitset(pCtx, pItem->pRecord->nItemId);
    }
    if (pCtx->nScrollRow != nFirst) {
        Ov008_RefreshInventoryRows(pCtx, pCtx->nRowBase, nFirst);
    } else {
        pItem = NNS_FndGetNthListObject(pCtx->pList, (u16)nFirst);
        while (pItem != 0) {
            if (GameState_IsFlagSet(pItem->pRecord->nItemId + FLAG_ITEM_HIDDEN) != 0) {
                Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i + ROW_WIDGET_A), 0);
            } else {
                Ov008_ReleaseTwoSlotsEx(nCtx, Ov008_FindEntryById(nCtx, i + ROW_WIDGET_A), (u16)(Ov008_TestBitInBitset(pCtx, pItem->pRecord->nItemId) != 0));
                Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i + ROW_WIDGET_A), 1);
            }
            if (pItem->nPlaced != 0) {
                Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i + ROW_WIDGET_B), 1);
            } else {
                Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i + ROW_WIDGET_B), 0);
            }
            i++;
            if (i >= VISIBLE_ROWS) {
                break;
            }
            pItem = NNS_FndGetNextListObject(pCtx->pList, pItem);
        }
    }
    Ov008_HighlightListRow(pCtx, nRow - pCtx->nScrollRow);
    return 1;
}
