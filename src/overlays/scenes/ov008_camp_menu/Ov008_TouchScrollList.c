/* Ov008_TouchScrollList -- Ov008_TouchScrollList: drive the list from the touch
 * state.  Without a touch the list is told its current word with no target
 * (-1) and both drag words are cleared.  A fresh touch (phase 0) becomes a scroll
 * target: the touch row centred on a row (y - height/2) relative to the current
 * scroll, clamped to [0, extent - height], committed with the immediate flag.
 */

#include "nitro/types.h"

typedef struct Ov008ScrollList {
    u32 nWord;                /* 0x00 */
    u8  pad_04[0x10];
    int nScroll;              /* 0x14 */
    int nExtent;              /* 0x18 */
    u8  pad_1c[8];
    int nRowHeight;           /* 0x24 */
    u8  pad_28[8];
    int nDragA;               /* 0x30 */
    int nDragB;               /* 0x34 */
} Ov008ScrollList;

typedef struct Ov008TouchState {
    u16 nX;                   /* 0x00 */
    u16 nY;                   /* 0x02 */
    u16 nTouching;            /* 0x04 */
    u16 nPhase;               /* 0x06 */
} Ov008TouchState;

#define NO_TARGET 0x7fffffff

extern int Ov008_GetCtxBlock4a80(void);                                     /* Ov008_GetCtxBlock4a80 */
extern void Ov008_GetTouchSample(int nCtx, void *pOut);                     /* copy the touch state */
extern void Ov008_ScrollListTo(Ov008ScrollList *pList, int nPos, int nTarget, int bNow);
extern void Ov008_MissionListSelectRow(Ov008ScrollList *pList, u32 nWord, int nTarget);

void Ov008_TouchScrollList(Ov008ScrollList *pList)
{
    Ov008TouchState touch;
    int nPos;
    int nMax;

    Ov008_GetTouchSample(Ov008_GetCtxBlock4a80(), &touch);
    if (touch.nTouching == 1) {
        if (touch.nPhase == 0) {
            nPos = touch.nY - pList->nRowHeight / 2 - pList->nScroll;
            if (nPos < 0) {
                nPos = 0;
            }
            nMax = pList->nExtent - pList->nRowHeight;
            if (nPos > nMax) {
                nPos = nMax;
            }
            Ov008_ScrollListTo(pList, nPos, NO_TARGET, 1);
        }
    } else {
        Ov008_MissionListSelectRow(pList, pList->nWord, -1);
        pList->nDragA = 0;
        pList->nDragB = 0;
    }
}
