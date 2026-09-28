/* Ov025_HighlightListRow -- Ov008_HighlightListRow: move the inventory list
 * highlight to visible row nRow.  Nothing while the menu is busy (+0x8) or
 * without a secondary panel (+0x4c).  In menu state 2 (+0x10) widget 3 is
 * offset by (0, nRow) fx32; the item at scroll row + nRow of the current
 * list (+0x300) has its id flagged in the bitset and, in state 2, its text
 * repainted in row 0 (colour 0xf3) and widget 0x4a shown with its shape
 * index (+0x24, hidden when none).  For a row inside 0..7 the previous
 * highlight (+0xa0) is cleared (0205f050 0) unless it is the same row, the
 * row's widget 400 + row shown with the item's bitset state (hidden while
 * game flag 0x37c9 + id is set), the new highlight drawn (0205f050 1) and
 * the row remembered.
 */

#include "nitro/types.h"

#define VISIBLE_ROWS  8
#define STATE_DRAG    2
#define WIDGET_DRAG   3
#define WIDGET_ICON   0x4a
#define ROW_WIDGET    400
#define FLAG_ITEM_HIDDEN 0x37c9
#define COLOUR_ACTIVE 0xf3

typedef struct UiLayoutPos {
    int nX;
    int nY;
} UiLayoutPos;

typedef struct Ov008Message15Record {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
    u8  pad_18[0xc];
    int nShapeIndex;          /* 0x24: -1 = none */
} Ov008Message15Record;

typedef struct Ov008InventoryItem {
    Ov008Message15Record *pRecord;  /* 0x00 */
} Ov008InventoryItem;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x8];
    int nBusy;                /* 0x0008 */
    u8  pad_000c[4];
    int menuState;            /* 0x0010 */
    u8  pad_0014[0x4c - 0x14];
    int bSecondaryPanel;      /* 0x004c */
    u8  pad_0050[0x74 - 0x50];
    int nScrollRow;           /* 0x0074 */
    u8  pad_0078[0xa0 - 0x78];
    int nHighlightRow;        /* 0x00a0 */
    u8  pad_00a4[0x300 - 0xa4];
    void *pList;              /* 0x0300: current inventory list */
    u8  pad_0304[0x1e68 - 0x304];
    int textList[4];          /* 0x1e68 */
} Ov008MenuContext;

extern int  Ov025_GetContext(void);                                    /* Ov008_GetContext */
extern void *Ov025_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void Ov025_ApplyOffsetSum(int nCtx, void *pEntry, UiLayoutPos *pPos); /* Ov008_ApplyOffsetSum */
extern Ov008InventoryItem *NNS_FndGetNthListObject(void *pList, int nIndex);        /* List_GetNthObject */
extern void Ov025_SetBitInBitset(Ov008MenuContext *pCtx, int nItemId);     /* Ov008_SetBitInBitset */
extern int  Ov025_GetItemDescriptionForMember(int *pList, Ov008Message15Record *pRecord); /* text index of a record */
extern void Ov025_RepaintTextRow(Ov008MenuContext *pCtx, int nRow, int nText, int nColour); /* Ov008_RepaintTextRow */
extern void Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);    /* SetEntrySlotsVisible */
extern void Ov025_ReleaseTwoSlotsEx_2(int nCtx, void *pEntry, int nFrame);      /* Ov008_ReleaseTwoSlotsEx */
extern void Ov025_EnqueueRowPalette(Ov008MenuContext *pCtx, int nRow, int bOn); /* draw / clear a row highlight */
extern int  GameState_IsFlagSet(int nFlag);                                     /* GameState_IsFlagSet */
extern int  Ov025_TestBitInBitset(Ov008MenuContext *pCtx, int nItemId);     /* TestBitInBitset */

void Ov025_HighlightListRow(Ov008MenuContext *pCtx, int nRow)
{
    UiLayoutPos pos = { 0, 0 };
    int nCtx;
    Ov008InventoryItem *pItem;
    void *pIcon;

    if (pCtx->nBusy != 0) {
        return;
    }
    if (pCtx->bSecondaryPanel == 0) {
        return;
    }
    nCtx = Ov025_GetContext();
    if (pCtx->menuState == STATE_DRAG) {
        pos.nY = nRow << 16;
        Ov025_ApplyOffsetSum(nCtx, Ov025_FindEntryById(nCtx, WIDGET_DRAG), &pos);
    }
    pItem = NNS_FndGetNthListObject(pCtx->pList, (u16)(pCtx->nScrollRow + nRow));
    if (pItem != 0) {
        Ov025_SetBitInBitset(pCtx, pItem->pRecord->nItemId);
        if (pCtx->menuState == STATE_DRAG) {
            Ov025_RepaintTextRow(pCtx, 0, Ov025_GetItemDescriptionForMember(pCtx->textList, pItem->pRecord), COLOUR_ACTIVE);
            pIcon = Ov025_FindEntryById(nCtx, WIDGET_ICON);
            if (pItem->pRecord->nShapeIndex >= 0) {
                Ov025_SetEntrySlotsVisible(nCtx, pIcon, 1);
                Ov025_ReleaseTwoSlotsEx_2(nCtx, pIcon, (u16)pItem->pRecord->nShapeIndex);
            } else {
                Ov025_SetEntrySlotsVisible(nCtx, pIcon, 0);
            }
        }
    }
    if (nRow >= 0 && nRow < VISIBLE_ROWS) {
        if (nRow != pCtx->nHighlightRow) {
            Ov025_EnqueueRowPalette(pCtx, pCtx->nHighlightRow, 0);
        }
        if (pItem != 0) {
            if (GameState_IsFlagSet(pItem->pRecord->nItemId + FLAG_ITEM_HIDDEN) != 0) {
                Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, nRow + ROW_WIDGET), 0);
            } else {
                Ov025_ReleaseTwoSlotsEx_2(nCtx, Ov025_FindEntryById(nCtx, nRow + ROW_WIDGET), (u16)(Ov025_TestBitInBitset(pCtx, pItem->pRecord->nItemId) != 0));
                Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, nRow + ROW_WIDGET), 1);
            }
        }
        Ov025_EnqueueRowPalette(pCtx, nRow, 1);
        pCtx->nHighlightRow = nRow;
    }
}
