/*
 * Ov002_PanelRefreshRing - rebuild the ring the cursor is on after something
 * changed underneath it.
 *
 * The slots are rebuilt first, and then the ring the classifier names is
 * repainted: the two list rings repaint their group and redraw the span strip
 * that covers them, the cached-entry ring repaints its entry, and the mode that
 * owns its own rows redraws them. All three of the rings that read the loaded
 * mask fall back to closing the panel down when that mask is empty. The slot
 * ring either re-applies a cursor that has nowhere to sit or refreshes its
 * header.
 *
 * The row for the current kind is repainted last, whatever happened above.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct {
    u8 bKind;                           /* +0x000 */
    u8 bMode;                           /* +0x001 */
    u8 pad0002[0x4aa];
    u8 bListRowBase;                    /* +0x4ac */
    u8 bListRowOffset;                  /* +0x4ad */
    u8 pad04ae[2];
    int nLoadedMask;                    /* +0x4b0 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_ClassifyCode(int *pOut, int nIndex);
extern int Ov002_PanelAnyListEntryAvailable(void);
extern void Ov002_DrawListSpanStrip(int nFirst, int nLast, int nGroup, int nKind);
extern void Ov002_PanelRefreshRowHeader(int nSource, int nFlag, int bSecond);
extern void Ov002_PanelRepaintForKind(int nMode, int nKind, int nValue);
extern void Ov002_RebuildPanelSlots(int nMode);
extern void Ov002_PanelApplyCursorMove(int nFrom, int nTo);
extern void Ov002_PanelRepaintListGroup(int nMode);
extern void Ov002_PanelRepaintSubListGroup(int nRow);
extern void Ov002_RedrawPartyStrip(void);
extern void Ov002_PanelRepaintCachedEntry(void);
extern void Ov002_HudReset(int nValue);
extern int Ov002_GetPanelField0058(void);

void Ov002_PanelRefreshRing(void)
{
    Ov002PanelSession *s;
    int nRow;
    int bSecond;
    int bAvailable;

    s = data_ov002_0207f620;
    Ov002_RebuildPanelSlots(s->bMode);
    switch (Ov002_ClassifyCode(&nRow, s->bMode)) {
    case 2:
        if (Ov002_GetPanelField0058() != 0 || s->nLoadedMask != 0) {
            Ov002_PanelRepaintListGroup(s->bMode);
            Ov002_DrawListSpanStrip(nRow + 1,
                                s->bListRowBase + s->bListRowOffset, 7, 0xb);
        } else {
            Ov002_HudReset(-1);
        }
        break;

    case 3:
        if (s->nLoadedMask != 0) {
            Ov002_PanelRepaintSubListGroup(nRow);
            Ov002_DrawListSpanStrip(s->bListRowBase + nRow + 1,
                                s->bListRowBase + s->bListRowOffset, 7, 0xb);
        } else {
            Ov002_HudReset(-1);
        }
        break;

    case 5:
        if (s->nLoadedMask != 0) {
            Ov002_PanelRepaintCachedEntry();
        } else {
            Ov002_HudReset(-1);
        }
        break;

    case 0:
        if (s->nLoadedMask == 0 && s->bKind == 2) {
            Ov002_PanelApplyCursorMove(s->bKind, 0);
            break;
        }
        if (s->bKind == 2) {
            bSecond = 1;
        } else {
            bSecond = 0;
        }
        if (Ov002_PanelAnyListEntryAvailable() != 0) {
            bAvailable = 1;
        } else {
            bAvailable = 0;
        }
        Ov002_PanelRefreshRowHeader(4, bAvailable, bSecond);
        break;

    case 4:
        Ov002_RedrawPartyStrip();
        break;
    }
    Ov002_PanelRepaintForKind(s->bMode, s->bKind, 0);
}
