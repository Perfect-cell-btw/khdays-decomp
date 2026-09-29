/*
 * Ov002_PanelAssignRowFromCursor - drop whatever the cursor is pointing at onto
 * one of the four group rows.
 *
 * From the grid the row takes the cell the cursor is on; from the first list it
 * takes the entry's key, and only when that entry still exists. Either way the
 * ring is repainted, the span strip covering it is redrawn, and the confirmation
 * sound plays.
 *
 * THUMB.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    u16 wKey;                           /* +0x00 */
    u16 wTag;                           /* +0x02 */
} Ov002PanelEntry;

typedef struct {
    u8 pad0000;
    u8 bMode;                           /* +0x001 */
    u8 bIndex;                          /* +0x002 */
    u8 bListIndex;                      /* +0x003 */
    u8 pad0004[0x2d];
    u8 bCursorRow;                      /* +0x031 */
    u8 aCells[0x44e];                   /* +0x032 */
    u8 aFirstList[0xc];                 /* +0x480 */
    u8 pad048c[0x20];
    u8 bListRowBase;                    /* +0x4ac */
    u8 bListRowOffset;                  /* +0x4ad */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern Ov002PanelEntry *NNS_FndGetNthListObject(void *pList, unsigned int nIndex);

extern int Ov002_ClassifyCode(int *pOut, int nIndex);
extern void Ov002_DrawListSpanStrip(int nFirst, int nLast, int nGroup, int nKind);
extern void Ov002_PanelAssignGroupRow(int nRow, unsigned int nGroup, unsigned int nKey);
extern void Ov002_PanelRepaintGroup(int nRow);
extern void Ov002_PanelRepaintListGroup(int nMode);

void Ov002_PanelAssignRowFromCursor(int nRow)
{
    Ov002PanelSession *s;
    Ov002PanelEntry *pEntry;
    int nPos;

    s = data_ov002_0207f620;
    switch (Ov002_ClassifyCode(&nPos, s->bMode)) {
    case 1:
        Ov002_PanelAssignGroupRow(nRow, 8, s->aCells[s->bIndex * 2]);
        Ov002_PanelRepaintGroup(nPos);
        Ov002_DrawListSpanStrip(nPos + 1, s->bCursorRow, 7, 0xb);
        PlaySound(0, 0);
        break;

    case 2:
        pEntry = NNS_FndGetNthListObject(s->aFirstList, s->bListIndex);
        if (pEntry != 0) {
            Ov002_PanelAssignGroupRow(nRow, 3, pEntry->wKey);
            Ov002_PanelRepaintListGroup(s->bMode);
            Ov002_DrawListSpanStrip(nPos + 1, s->bListRowBase + s->bListRowOffset, 7,
                                0xb);
            PlaySound(0, 0);
        }
        break;
    }
}
