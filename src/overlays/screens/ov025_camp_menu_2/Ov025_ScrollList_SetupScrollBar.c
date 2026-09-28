/* Ov025_ScrollList_SetupScrollBar -- Ov025_ScrollList_SetupScrollBar: size the scroll bar for the list's
 * rows (+8).  The pixel scroll (+0x2d0) and the knob (+0x2dc) start at 0, the scroll range
 * (+0x2d8) is 16 a row beyond the ten in view, the knob height (+0x2e0) 0xa0 for up to ten
 * rows and 0x6400 / (16 * rows) otherwise (the 64-bit divide 02020400), at least 0x20, and the
 * knob range (+0x2e4) the bar less the knob.  Of the bar entries 4..0x13 of the 4a80 block
 * (02084a8c) those within the knob height less 16 are shown (0208884c), the caps 2 and 3
 * shown, the second pair of every entry 2..0x13 released (020888b0) and the bar placed
 * (Ov025_ScrollList_PlaceKnobBar 020add28). */
#include "nitro/types.h"

typedef struct TileBlock {
    u8   pad_00[0x20];
    void *pData;              /* 0x20 */
} TileBlock;

typedef struct TileSurface {
    void *pixels;             /* 0x00 */
    int  width;               /* 0x04 */
    int  height;              /* 0x08 */
    int  totalBytes;          /* 0x0c */
    int  rowBytes;            /* 0x10 */
    int  unknown14;           /* 0x14 */
    TileBlock *current;       /* 0x18 */
    void *currentData;        /* 0x1c */
    u8   pad_20[0x3c - 0x20];
} TileSurface;                /* 0x3c */

typedef struct Ov025ScrollRow {
    int  nMission;            /* 0x00 */
    int  nDay;                /* 0x04 */
    const u16 *pName;         /* 0x08 */
    int  nField0c;            /* 0x0c */
} Ov025ScrollRow;             /* 0x10 */

typedef struct Ov025ScrollList {
    int  nField000;           /* 0x000 */
    Ov025ScrollRow *pRows;    /* 0x004: the day rows */
    int  nCount;              /* 0x008 */
    int  bTouching;           /* 0x00c: the stylus holds the scroll bar */
    int  bPressed;            /* 0x010 */
    int  bRowsDirty;          /* 0x014: re-upload the row surfaces */
    int  bMarkersDirty;       /* 0x018: re-upload the marker screen */
    u8   strings[0x10];       /* 0x01c: the row name strings */
    void *pNode;              /* 0x02c: the shared UI list node */
    TileSurface aSurface[11]; /* 0x030: one text surface per row */
    int  bDirty;              /* 0x2c4 */
    int  nCursor;             /* 0x2c8 */
    int  nField2cc;           /* 0x2cc */
    int  nScroll;             /* 0x2d0: in pixels, 16 per row */
    int  nPrevScroll;         /* 0x2d4 */
    int  nScrollMax;          /* 0x2d8 */
    int  nKnob;               /* 0x2dc */
    int  nKnobHeight;         /* 0x2e0 */
    int  nKnobMax;            /* 0x2e4 */
} Ov025ScrollList;            /* 0x2e8: the day list view of page B (Ov025_GetPageB) */

extern int   func_02020400(int nNum, int nDen);                     /* _s32_div_f */
extern int   Ov025_GetBlock4a80(void);                             /* Ov008_GetCtxBlock4a80 */
extern void *Ov025_FindEntryById(int nCtx, int nId);                /* FindEntryById */
extern void  Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */
extern void  Ov025_ReleaseTwoSlots(int nCtx, void *pEntry);           /* Ov008_ReleaseTwoSlots */
extern void  Ov025_ScrollList_PlaceKnobBar(Ov025ScrollList *pList);           /* Ov025_ScrollList_PlaceKnobBar */

void Ov025_ScrollList_SetupScrollBar(Ov025ScrollList *pList)
{
    int nCtx;
    int i;
    int nHidden;
    int nShown;

    pList->nScroll = 0;
    pList->nScrollMax = (pList->nCount - 10) * 16;
    if (pList->nScrollMax < 0) {
        pList->nScrollMax = 0;
    }
    pList->nKnob = 0;
    pList->nKnobHeight = 0xa0;
    if (pList->nCount > 10) {
        pList->nKnobHeight = func_02020400(0x6400, pList->nCount << 4);
    }
    if (pList->nKnobHeight < 0x20) {
        pList->nKnobHeight = 0x20;
    }
    pList->nKnobMax = 0xa0 - pList->nKnobHeight;
    nCtx = Ov025_GetBlock4a80();
    nHidden = 0;
    nShown = 1;
    for (i = 4; i <= 0x13; i++) {
        if ((i - 3) * 8 < pList->nKnobHeight - 0x10) {
            Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, i), nShown);
        } else {
            Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, i), nHidden);
        }
    }
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 2), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 3), 1);
    for (i = 2; i <= 0x13; i++) {
        Ov025_ReleaseTwoSlots(nCtx, Ov025_FindEntryById(nCtx, i));
    }
    Ov025_ScrollList_PlaceKnobBar(pList);
}
