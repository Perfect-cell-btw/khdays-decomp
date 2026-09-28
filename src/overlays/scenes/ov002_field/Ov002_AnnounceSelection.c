extern int Ov002_ForwardToSubDc(int id);
extern void Ov002_ForwardToSubDc_2(int);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int);
extern int Ov002_FindSlotByKey(int a);
extern void Ov002_PanelDrawSlotCursor(unsigned short sel, int b);
extern void Ov002_TakeLock(int a);
extern char *data_ov002_0207f620;

/* Announces the highlighted entry, unless a modal is up: "none" when nothing is selected, and
 * one of two lead-ins otherwise. */
void Ov002_AnnounceSelection(int a, int b) {
    int sel;
    if (*(int *)(data_ov002_0207f620 + 0x5dc) != 0) {
        return;
    }
    Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x4e));
    sel = Ov002_FindSlotByKey(a);
    if (sel < 0) {
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x5d));
        Ov002_PanelDrawSlotCursor(0xffff, b);
    } else {
        if (b != 0) {
            Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x4a));
        } else {
            Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x4e));
        }
        Ov002_PanelDrawSlotCursor((unsigned short)sel, b);
    }
    Ov002_TakeLock(0);
}
