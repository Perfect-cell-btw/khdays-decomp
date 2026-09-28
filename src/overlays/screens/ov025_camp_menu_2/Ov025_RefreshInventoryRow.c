/* Ov025_RefreshInventoryRow -- Ov008_RefreshInventoryRow: redraw the visible
 * inventory row that holds item nItemId.  Nothing while the grid is busy
 * (+0x8).  Starting from the list object at the scroll position (+0x74, list
 * +0x300), at most eight rows are walked until the row's record names the
 * item (+0x14).  A fixed record (category 2) is drawn with colour 0xf5 and the
 * row's state word (+0x1704, stride 0x28) cleared; any other record is drawn
 * with 0xf3 while copies remain to place, 0xf5 once all are placed (state 1),
 * and gets its placed / owned counts drawn (0205e0f4).  The row's widget
 * (500 + row) is shown while any copy is placed, hidden otherwise.
 */

#include "nitro/types.h"

#define ROW_COUNT       8
#define WIDGET_ROW_BASE 500
#define CATEGORY_FIXED  2
#define COLOUR_ACTIVE   0xf3
#define COLOUR_DONE     0xf5

typedef struct Ov008Message15Record {
    u8   pad_00[0xc];
    void *pName;              /* 0x0c */
    u8   pad_10[4];
    int  nItemId;             /* 0x14 */
    int  nCategory;           /* 0x18 */
} Ov008Message15Record;

typedef struct Ov008InventoryItem {
    Ov008Message15Record *pRecord;  /* 0x00 */
    u8  nCount;               /* 0x04 */
    u8  nPlaced;              /* 0x05 */
} Ov008InventoryItem;

typedef struct Ov008RowState {
    int nState;               /* 0x00 */
    u8  pad_04[0x28 - 4];
} Ov008RowState;

typedef struct Ov008MenuContext {
    u8  pad_0000[8];
    int nBusy;                /* 0x0008 */
    u8  pad_000c[0x74 - 0xc];
    int nScrollRow;           /* 0x0074 */
    u8  pad_0078[0x300 - 0x78];
    void *pList;              /* 0x0300 */
    u8  pad_0304[0x1704 - 0x304];
    Ov008RowState aRow[ROW_COUNT]; /* 0x1704 */
} Ov008MenuContext;

extern int   Ov025_GetContext(void);                                  /* Ov008_GetContext */
extern Ov008InventoryItem *NNS_FndGetNthListObject(void *pList, int nIndex);       /* List_GetNthObject */
extern Ov008InventoryItem *NNS_FndGetNextListObject(void *pList, void *pObject);
extern void  Ov025_UploadTileSlot(Ov008MenuContext *pCtx, int nRow, void *pText, int nColour); /* Ov008_UploadTileSlot */
extern void  Ov025_DrawRowCountDigits(Ov008MenuContext *pCtx, int nRow, int nPlaced, int nCount); /* draw the counts */
extern void *Ov025_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern void  Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);  /* SetEntrySlotsVisible */

void Ov025_RefreshInventoryRow(Ov008MenuContext *pCtx, int nItemId)
{
    Ov008InventoryItem *pItem;
    int nRow;
    int nCtx;
    Ov008Message15Record *pRecord;

    nCtx = Ov025_GetContext();
    if (pCtx->nBusy != 0) {
        return;
    }
    pItem = NNS_FndGetNthListObject(pCtx->pList, (u16)pCtx->nScrollRow);
    for (nRow = 0; nRow < ROW_COUNT; nRow++) {
        pRecord = pItem->pRecord;
        if (pRecord->nItemId == nItemId) {
            if (pRecord->nCategory == CATEGORY_FIXED) {
                Ov025_UploadTileSlot(pCtx, nRow, pRecord->pName, COLOUR_DONE);
                pCtx->aRow[nRow].nState = 0;
            } else {
                if (pItem->nPlaced >= pItem->nCount) {
                    Ov025_UploadTileSlot(pCtx, nRow, pRecord->pName, COLOUR_DONE);
                    pCtx->aRow[nRow].nState = 1;
                } else {
                    Ov025_UploadTileSlot(pCtx, nRow, pRecord->pName, COLOUR_ACTIVE);
                    pCtx->aRow[nRow].nState = 0;
                }
                Ov025_DrawRowCountDigits(pCtx, nRow, pItem->nPlaced, pItem->nCount);
            }
            if (pItem->nPlaced != 0) {
                Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, nRow + WIDGET_ROW_BASE), 1);
            } else {
                Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, nRow + WIDGET_ROW_BASE), 0);
            }
            return;
        }
        pItem = NNS_FndGetNextListObject(pCtx->pList, pItem);
    }
}
