extern int Ov002_ForwardToSubDc(unsigned short id);
extern void Ov002_Ctx_InvokeTagTrackerCallback(void);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_3(int handle, unsigned char slot);
extern int data_ov002_0207dd14;

/* Prints one help page: the page title, the entry the cursor is on, the "back" line on page 0,
 * and the footer -- twice, once through the slot-aware printer. */
void Ov002_PrintHelpPage(int page, int *cursor) {
    char *row = (char *)&data_ov002_0207dd14 + page * 0x18;
    Ov002_ForwardToSubDc((unsigned short)*(int *)row);
    Ov002_Ctx_InvokeTagTrackerCallback();
    Ov002_ForwardToSubDc((unsigned short)*(int *)(row + *cursor * 4 + 4));
    Ov002_Ctx_InvokeTagTrackerCallback();
    if (page == 0) {
        Ov002_ForwardToSubDc(1);
        Ov002_Ctx_InvokeTagTrackerCallback();
    }
    Ov002_Ctx_SetTagTrackerNodeArmed_3(Ov002_ForwardToSubDc((unsigned short)*(int *)(row + 0x14)),
                        (unsigned char)(page + 2));
    Ov002_ForwardToSubDc((unsigned short)*(int *)(row + 0x14));
    Ov002_Ctx_InvokeTagTrackerCallback();
}
