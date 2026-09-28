/*
 * Ov002_PanelSetHelpVisible - show or hide the help strip, and tell the ring
 * the cursor is on about it.
 *
 * The request is forced off while the panel is in its restricted state. If the
 * strip is already where it was asked to be, nothing happens at all; otherwise
 * the new state is stored and the ring the cursor sits on is refreshed: the
 * slot ring rebuilds its labels and, when the strip is going away with the
 * cursor on row 1, re-applies the cursor; the grid either tears the strip down
 * or rebuilds its labels and re-opens it on the row the classifier handed back;
 * the mode that owns its own rows just rebuilds them.
 *
 * THUMB.
 */

typedef unsigned char u8;

typedef struct {
    u8 bKind;                           /* +0x000 */
    u8 bMode;                           /* +0x001 */
    u8 pad0002[0x4a6];
    int nHelpVisible;                   /* +0x4a8 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_ClassifyCode(int *pOut, int nIndex);
extern int Ov002_GetPanelField0058(void);
extern void Ov002_RebuildPanelSlots(int nMode);
extern void Ov002_PanelApplyCursorMove(int nFrom, int nTo);
extern void Ov002_PanelRefreshAllRowHeaders(void);
extern void Ov002_PanelRepaintGroup(int nRow);
extern void Ov002_RedrawPartyStrip(void);
extern void Ov002_HudReset(int nValue);

void Ov002_PanelSetHelpVisible(int nVisible)
{
    Ov002PanelSession *s;
    int nClass;
    int nRow;

    s = data_ov002_0207f620;
    nClass = Ov002_ClassifyCode(&nRow, s->bMode);
    if (Ov002_GetPanelField0058() != 0) {
        nVisible = 0;
    }
    if (s->nHelpVisible == nVisible) {
        return;
    }
    s->nHelpVisible = nVisible;

    switch (nClass) {
    case 0:
        Ov002_RebuildPanelSlots(s->bMode);
        if (nVisible == 0 && s->bKind == 1) {
            Ov002_PanelApplyCursorMove(s->bKind, 0);
        }
        Ov002_PanelRefreshAllRowHeaders();
        return;

    case 1:
        if (nVisible == 0) {
            Ov002_HudReset(-1);
            return;
        }
        Ov002_RebuildPanelSlots(s->bMode);
        Ov002_PanelRepaintGroup(nRow);
        return;

    case 4:
        Ov002_RedrawPartyStrip();
        return;
    }
}
