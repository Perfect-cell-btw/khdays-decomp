/* Ov008_DragScrollGauge -- Ov008_DragScrollGauge: continue a scroll-gauge drag on
 * page B's scroll menu.  While the pen is down and moving (touch phase 0) the
 * knob follows the touch y (recentred, clamped to [0, 0x80 - scale]), the list
 * window is redrawn at the knob row and the selection kept within the eight
 * rows starting at the knob's row (offset + 8) / 16; the row flag is raised.
 * When the pen is up, widget 5 is reset to frame 0 and shown and the drag flag
 * cleared.
 */
#include "nitro/types.h"

typedef struct Ov008ScrollMenu {
    int bDragging;            /* 0x000 */
    int bRowMoved;            /* 0x004 */
    u8  pad_008[0x40 - 0x8];
    int nKnobOffset;          /* 0x040 */
    u8  pad_044[8];
    int nGaugeScale;          /* 0x04c */
    int nSelectedRow;         /* 0x050 */
} Ov008ScrollMenu;

typedef struct Ov008TouchState {
    u16 nX;                   /* 0x00 */
    u16 nY;                   /* 0x02 */
    u16 nTouching;            /* 0x04 */
    u16 nPhase;               /* 0x06 */
} Ov008TouchState;

#define KNOB_PAD    8
#define GAUGE_SPAN  0x80
#define ROWS_VISIBLE 8
#define WIDGET_SCROLL_HINT 5

extern int  Ov008_GetCtxBlock4a80(void);                                    /* Ov008_GetCtxBlock4a80 */
extern Ov008ScrollMenu *Ov008_GetPageB(void);                        /* Ov008_GetPageB */
extern int  Ov008_GetCtxBlock954c(void);                                    /* Ov008_GetCtxBlock954c */
extern void Ov008_GetPoint1C(int nBlock, void *pOut);                  /* copy the touch record */
extern void Ov008_SetScrollGaugePos(Ov008ScrollMenu *pMenu, int nPos);        /* Ov008_SetScrollGaugePos */
extern int  Ov008_DrawListWindow(Ov008ScrollMenu *pMenu, int nCenter, int bFinalize, int bReport); /* Ov008_DrawListWindow */
extern void *Ov008_FindEntryById(int nBlock, int nId);                    /* FindEntryById */
extern void Ov008_ReleaseTwoSlotsEx(int nBlock, void *pEntry, int nFrame);    /* Ov008_ReleaseTwoSlotsEx */
extern void Ov008_SetEntrySlotsVisible(int nBlock, void *pEntry, int bVisible);  /* SetEntrySlotsVisible */

void Ov008_DragScrollGauge(Ov008ScrollMenu *pDrag)
{
    int nBlock;
    Ov008ScrollMenu *pMenu;
    Ov008TouchState touch;
    int nPos;
    int nMax;
    int nRow;

    nBlock = Ov008_GetCtxBlock4a80();
    pMenu = Ov008_GetPageB();
    Ov008_GetPoint1C(Ov008_GetCtxBlock954c(), &touch);
    if (touch.nTouching == 1) {
        if (touch.nPhase != 0) {
            return;
        }
        nPos = touch.nY - pMenu->nGaugeScale / 2 - KNOB_PAD;
        if (nPos < 0) {
            nPos = 0;
        }
        nMax = GAUGE_SPAN - pMenu->nGaugeScale;
        if (nPos > nMax) {
            nPos = nMax;
        }
        Ov008_SetScrollGaugePos(pMenu, nPos);
        nRow = pMenu->nKnobOffset / 16;
        if (nRow < 0) {
            nRow = 0;
        }
        Ov008_DrawListWindow(pMenu, nRow, 0, 0);
        nRow = (pMenu->nKnobOffset + KNOB_PAD) / 16;
        if (pMenu->nSelectedRow >= nRow + ROWS_VISIBLE) {
            pMenu->nSelectedRow = nRow + ROWS_VISIBLE - 1;
        }
        if (pMenu->nSelectedRow < nRow) {
            pMenu->nSelectedRow = nRow;
        }
        pDrag->bRowMoved = 1;
    } else {
        Ov008_ReleaseTwoSlotsEx(nBlock, Ov008_FindEntryById(nBlock, WIDGET_SCROLL_HINT), 0);
        Ov008_SetEntrySlotsVisible(nBlock, Ov008_FindEntryById(nBlock, WIDGET_SCROLL_HINT), 1);
        pDrag->bDragging = 0;
    }
}
