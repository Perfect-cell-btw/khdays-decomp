extern int Ov002_Ctx_FindActiveEntryByTag(int id);
extern void Ov002_ForwardToSubDc_3(void);
extern void Ov002_ForwardToSubDc(int id);
extern void Ov002_ForwardToSubDc_2(void);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int handle, int mode);

/* Refreshes widget 1: mode 0 restores the default caption, any other mode prints line 0x3c. */
void Ov002_RefreshCaptionWidget(int mode) {
    int handle = Ov002_Ctx_FindActiveEntryByTag(1);
    if (mode != 0) {
        Ov002_ForwardToSubDc_3();
    } else {
        Ov002_ForwardToSubDc(0x3c);
        Ov002_ForwardToSubDc_2();
    }
    Ov002_Ctx_SetTagTrackerNodeArmed_5(handle, mode);
}
