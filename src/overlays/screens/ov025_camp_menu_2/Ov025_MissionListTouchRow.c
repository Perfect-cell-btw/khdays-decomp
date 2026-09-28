/* Ov025_MissionListTouchRow -- Ov008_MissionListTouchRow: pick a mission row from a
 * fresh touch.  Only while the list is idle (not animating, no selection
 * pending, not locked) and the touch record reports a fresh touch.  A touch at
 * x >= 0xe0 flags the scroll-bar drag (nScrollA) instead.  Otherwise the row is
 * (scroll + y - top) / 32, provided the touch is above the list's bottom margin
 * (top + height - 2) and the row exists: touching the selected row confirms it,
 * any other row selects it; nScrollB is flagged either way.
 */
#include "nitro/types.h"

typedef struct Ov008MissionList {
    int nSelected;            /* 0x000: -1 = none */
    u8  pad_004[0x0c - 0x04];
    int nScroll;              /* 0x00c */
    u8  pad_010[4];
    int nTop;                 /* 0x014 */
    int nHeight;              /* 0x018 */
    u8  pad_01c[0x30 - 0x1c];
    int nScrollA;             /* 0x030 */
    int nScrollB;             /* 0x034 */
    u8  pad_038[0x68 - 0x38];
    int bAnimating;           /* 0x068 */
    u8  pad_06c[0x4f8 - 0x6c];
    int bSelectionPending;    /* 0x4f8 */
    int bSelectionArmed;      /* 0x4fc */
    int bLocked;              /* 0x500 */
} Ov008MissionList;

typedef struct Ov008TouchState {
    u16 nX;                   /* 0x00 */
    u16 nY;                   /* 0x02 */
    u16 nTouching;            /* 0x04 */
    u16 nPhase;               /* 0x06 */
} Ov008TouchState;

#define SCROLLBAR_X 0xe0
#define ROW_HEIGHT  32

extern Ov008MissionList *Ov025_GetPageB(void);                       /* Ov008_GetPageB */
extern int Ov025_GetCtxBlock954c(void);                                     /* Ov008_GetCtxBlock954c */
extern void Ov025_GetPoint1C(int nBlock, void *pOut);                  /* copy the touch record */
extern u16 Ov025_GetCurrentListId(void);                                     /* mission entry count */
extern void Ov025_MissionListConfirm(Ov008MissionList *pList);                 /* Ov008_MissionListConfirm */
extern void Ov025_MissionListSelectRow(Ov008MissionList *pList, u32 nWord, int nTarget);

void Ov025_MissionListTouchRow(void)
{
    Ov008TouchState touch;
    Ov008MissionList *pList;
    int nRow;

    pList = Ov025_GetPageB();
    if (pList->bAnimating != 0 || pList->bSelectionPending != 0 || pList->bLocked != 0) {
        return;
    }
    Ov025_GetPoint1C(Ov025_GetCtxBlock954c(), &touch);
    if (touch.nTouching != 1 || touch.nPhase != 0) {
        return;
    }
    if (touch.nX < SCROLLBAR_X) {
        nRow = (pList->nScroll + (touch.nY - pList->nTop)) / ROW_HEIGHT;
        if (touch.nY < pList->nTop + pList->nHeight - 2) {
            if (nRow < Ov025_GetCurrentListId()) {
                if (pList->nSelected == nRow) {
                    Ov025_MissionListConfirm(pList);
                } else {
                    Ov025_MissionListSelectRow(pList, nRow, 0);
                }
                pList->nScrollB = 1;
            }
        }
    } else {
        pList->nScrollA = 1;
    }
}
