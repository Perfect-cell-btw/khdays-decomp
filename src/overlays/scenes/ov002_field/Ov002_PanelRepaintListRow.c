/* Repaint one list-backed panel row -- the list counterpart of the plain row
 * repaint.
 *
 * A negative index means there is no row: the glyph block falls back to the
 * blank one and no entry is fetched. Otherwise the block is nIndex*16 + 0x250
 * and the entry comes from the list by ordinal.
 *
 * The palette is picked from two pairs rather than one: bAlt chooses between
 * 0xc/0x7 and 0xf/0xe, and bEnabled picks within the pair. The style comes from
 * the group-3 slot lookup on the entry's key, but only when an entry exists and
 * the panel state is set, and it is translated through one of two four-entry
 * tables depending on alignment.
 *
 * The row finally draws the entry's tag, unless there is no entry or its flag
 * word is set, in which case it draws a zero counter instead.
 *
 * The declaration order of the locals is load-bearing: it is what puts the
 * entry pointer above the glyph block in the callee-saved range.
 */

#include "nitro/types.h"

typedef struct {
    void *pHead;
    void *pTail;
    u16 nCount;
    u16 nLinkOffset;
} NNSFndList;

typedef struct {
    u16 nKey;               /* +0x00 */
    u16 nTag;               /* +0x02 */
    int nState;             /* +0x04 */
    int nField0008;         /* +0x08 */
} Ov002PanelEntry;

typedef struct {
    u8 pad0000[0x10];
    int nState;             /* +0x10 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;
extern int data_ov002_0207de50[];
extern int data_ov002_0207de60[];

extern Ov002PanelEntry *NNS_FndGetNthListObject(NNSFndList *pList, u16 nIndex);
extern int Ov002_PanelFindGroupSlot(int nGroup, int nKey);
extern void Ov002_PanelWriteSlotLabel(int nSlot, int nColumn, int nTile,
                                int nPalette, int bRightAlign);
extern void Ov002_PanelPushSlotState(int nSlot, int nState, int nValue);
extern void Ov002_Panel_DrawCounter(int nSlot, int nValue, int nColumn,
                                int bRightAlign);
extern void Ov002_PanelDrawCounter(int nSlot, int nValue, int nColumn,
                                int bRightAlign, int bShowZero);
extern void Ov002_SelectEntry(int nItemId);

void Ov002_PanelRepaintListRow(NNSFndList *pList, int nIndex, int nSlot, int nEntry,
                         int nColumn, int bEnabled, int bRightAlign,
                         int bAlt) {
    Ov002PanelSession *s = data_ov002_0207f620;
    u16 nPalette;
    int nSlotState;
    u16 nTile;
    int nStyle;
    Ov002PanelEntry *pEntry;

    pEntry = 0;

    if (nIndex < 0) {
        nTile = 0x3d0;
    } else {
        nTile = nIndex * 16 + 0x250;
        pEntry = NNS_FndGetNthListObject(pList, nEntry);
    }

    if (bAlt != 0) {
        nPalette = bEnabled ? 0xc : 7;
    } else {
        nPalette = bEnabled ? 0xf : 0xe;
    }
    Ov002_PanelWriteSlotLabel(nSlot, nColumn, nTile, nPalette, bRightAlign);

    if (pEntry != 0 && s->nState != 0) {
        nStyle = Ov002_PanelFindGroupSlot(3, pEntry->nKey);
    } else {
        nStyle = -1;
    }

    if (bRightAlign != 0) {
        nSlotState = nStyle >= 0 ? data_ov002_0207de50[nStyle] : 0;
    } else {
        nSlotState = nStyle >= 0 ? data_ov002_0207de60[nStyle] : 1;
    }
    Ov002_PanelPushSlotState(nSlot, nSlotState, nColumn);

    if (nIndex >= 0 && pEntry->nField0008 == 0) {
        Ov002_Panel_DrawCounter(nSlot, pEntry->nTag, nColumn, bRightAlign);
    } else {
        Ov002_PanelDrawCounter(nSlot, 0, nColumn, bRightAlign, 0);
    }
    Ov002_SelectEntry(9);
    Ov002_SelectEntry(0xb);
}
