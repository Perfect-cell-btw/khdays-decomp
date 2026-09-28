/* Refresh the three panel row headers for the current kind, then replay the
 * 0x5a sub request and re-select entry 0xb. */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 bKind;               /* +0x0 */
    u8 pad0001[0xb];
    int nPrimaryValue;      /* +0xc */
    u8 pad0010[4];
    u16 wPrimaryRow;        /* +0x14 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_PanelAnyListEntryAvailable(void);
extern int Ov002_PanelAnyCellAvailable(void);
extern void Ov002_PanelRefreshRowHeader(int nSlot, int nValue, int nFlag);
extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nEntry);
extern void Ov002_SelectEntry(int nId);

void Ov002_PanelRefreshAllRowHeaders(void) {
    Ov002PanelSession *s = data_ov002_0207f620;
    int bItems = (s->bKind == 2);
    int nAvail = Ov002_PanelAnyListEntryAvailable();

    Ov002_PanelRefreshRowHeader(4, nAvail != 0, bItems);
    Ov002_PanelRefreshRowHeader(s->wPrimaryRow, s->nPrimaryValue, s->bKind == 0);

    if (s->bKind == 1) {
        Ov002_PanelRefreshRowHeader(3, Ov002_PanelAnyCellAvailable(), 1);
    } else {
        Ov002_PanelRefreshRowHeader(3, Ov002_PanelAnyCellAvailable(), 0);
    }

    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x5a));
    Ov002_SelectEntry(0xb);
}
