/* Refresh the panel for whatever mode it is currently in.
 *
 * First the list index is clamped to the live entry count, stepping back one
 * when the count is positive. Then the mode is classified and dispatched: class
 * 0 refreshes the row-4 header, except that kind 2 with both lists empty applies
 * a cursor move instead; class 2 recomputes the mode and kind from the list
 * index, repaints the list group, pushes the row widget, reopens the tracker if
 * it is closed, and runs the kind repaint. Either way it ends by handing the
 * mode on.
 *
 * The list index is an unsigned char, so it promotes to int and the divisions
 * by six come out signed -- magic multiply plus the lsr #31 correction -- even
 * though the value can never be negative. Writing them as unsigned loses that.
 */
typedef unsigned char u8;

typedef struct {
    u8 bKind;                   /* +0x00 */
    u8 bMode;                   /* +0x01 */
    u8 pad0002;
    u8 bListIndex;              /* +0x03 */
    u8 pad0004[0x4a8];
    u8 bListRowBase;            /* +0x4ac */
    u8 bListRowOffset;          /* +0x4ad */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_CountPanelListEntries(void);
extern int Ov002_CountSecondListEntries(void);
extern int Ov002_ClassifyCode(int *pOut, int nMode);
extern int Ov002_PanelAnyListEntryAvailable(void);
extern void Ov002_PanelRefreshRowHeader(int nRow, int bEnabled, int bRightAlign);
extern void Ov002_PanelApplyCursorMove(int nFrom, int nTo);
extern void Ov002_PanelRepaintListGroup(int nCode);
extern void Ov002_DrawListSpanStrip(int a, int b, int c, int d);
extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern int Ov002_ForwardToSubDc_4(int nHandle);
extern int Ov002_ForwardToSubDc(int nTag);
extern void Ov002_ForwardToSubDc_2(int nHandle);
extern void Ov002_PanelRepaintForKind(int nMode, int nKind, int nFlag);
extern void Ov002_RebuildPanelSlots(int nMode);

void Ov002_PanelRefreshCurrentMode(void) {
    Ov002PanelSession *s = data_ov002_0207f620;
    int nClass;
    int nCount;

    nCount = Ov002_CountPanelListEntries();
    if (s->bListIndex >= nCount) {
        if (nCount > 0) {
            nCount--;
        }
        s->bListIndex = nCount;
    }

    switch (Ov002_ClassifyCode(&nClass, s->bMode)) {
    case 0:
        if (s->bKind == 2) {
            if (Ov002_CountPanelListEntries() + Ov002_CountSecondListEntries() > 0) {
                Ov002_PanelRefreshRowHeader(4, Ov002_PanelAnyListEntryAvailable(), 1);
            } else {
                Ov002_PanelApplyCursorMove(s->bKind, 0);
            }
        } else {
            Ov002_PanelRefreshRowHeader(4, Ov002_PanelAnyListEntryAvailable(), 0);
        }
        break;

    case 2:
        s->bMode = s->bListIndex / 6 + 4;
        s->bKind = s->bListIndex % 6;
        Ov002_PanelRepaintListGroup(s->bMode);
        Ov002_DrawListSpanStrip(nClass + 1,
                            s->bListRowBase + s->bListRowOffset, 7, 0xb);
        if (Ov002_ForwardToSubDc_4(Ov002_Ctx_FindActiveEntryByTag(0xe)) == 0) {
            Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x79));
        }
        Ov002_PanelRepaintForKind(s->bMode, s->bListIndex % 6, 0);
        break;
    }

    Ov002_RebuildPanelSlots(s->bMode);
}
