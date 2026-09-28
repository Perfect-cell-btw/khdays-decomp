/* Ov025_UpdateListCursorCells -- Ov008_UpdateListCursorCells: refresh the mission list's
 * cursor cells on the ctx tracker (block 954c).  Without a modal object and with
 * touch enabled: a selection shows the cursor cell (tag 1), none (and not
 * animating) shows the idle cell (tag 9).  A valid word-1 shows tag 8 with frame
 * 2 at row * 4 (as a short); a selection (not animating) puts tag 7 at
 * (selection - scroll / 32) * 4, remembering that row at +8.  Always marks
 * the cells refreshed (+0x4c).
 */
#include "nitro/types.h"

typedef struct Ov008MissionList {
    int nSelected;            /* 0x000 */
    int nWord1;               /* 0x004 */
    int nCursorRow;           /* 0x008 */
    int nScroll;              /* 0x00c */
    u8  pad_010[0x38 - 0x10];
    int bTouchEnabled;        /* 0x038 */
    u8  pad_03c[0x4c - 0x3c];
    int bCellsRefreshed;      /* 0x04c */
    u8  pad_050[0x68 - 0x50];
    int bAnimating;           /* 0x068 */
} Ov008MissionList;

#define ROW_HEIGHT 32
#define TAG_CURSOR 1
#define TAG_IDLE   9
#define TAG_WORD   8
#define TAG_SELECT 7

extern int  Ov025_GetBlock4a80(void);                                    /* Ov008_GetCtxBlock4a80 */
extern int  Ov025_GetCtxBlock954c(void);                                    /* Ov008_GetCtxBlock954c */
extern int  Ov025_GetCtxObject9630(void);                                    /* Ov008_GetCtxObject9630 */
extern int  Ov025_FindEntryByTag(int nTracker, int nTag);                  /* ov008_FindEntryByTag */
extern void Ov025_TagTracker_InvokeCallback(int nTracker, int nCell);                 /* Ov008_TagTracker_InvokeCallback */
extern void Ov025_ApplyTempFieldsAndRestore(int nTracker, int nCell, int nFrame, short nY); /* Ov008_ApplyTempFieldsAndRestore */

void Ov025_UpdateListCursorCells(Ov008MissionList *pList)
{
    int nTracker;
    int nFirst;
    int nRow;

    Ov025_GetBlock4a80();
    nTracker = Ov025_GetCtxBlock954c();
    if (Ov025_GetCtxObject9630() == 0 && pList->bTouchEnabled != 0) {
        if (pList->nSelected >= 0) {
            Ov025_TagTracker_InvokeCallback(nTracker, Ov025_FindEntryByTag(nTracker, TAG_CURSOR));
        }
        if (pList->nSelected < 0 && pList->bAnimating == 0) {
            Ov025_TagTracker_InvokeCallback(nTracker, Ov025_FindEntryByTag(nTracker, TAG_IDLE));
        }
    }
    if (pList->nWord1 >= 0) {
        Ov025_ApplyTempFieldsAndRestore(nTracker, Ov025_FindEntryByTag(nTracker, TAG_WORD), 2, (short)(pList->nCursorRow * 4));
    }
    nFirst = pList->nScroll / ROW_HEIGHT;
    if (pList->nSelected >= 0 && pList->bAnimating == 0) {
        nRow = pList->nSelected - nFirst;
        Ov025_ApplyTempFieldsAndRestore(nTracker, Ov025_FindEntryByTag(nTracker, TAG_SELECT), 2, (short)(nRow * 4));
        pList->nCursorRow = nRow;
    }
    pList->bCellsRefreshed = 1;
}
