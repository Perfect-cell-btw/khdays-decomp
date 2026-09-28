/* Open the confirmation prompt: latch the pending flag and its two payload words
 * at +0x178..+0x184, seed both scroll halves at +0x180/+0x182 from the current
 * row height at +0x3a, disarm the tag-tracker node for tag 0x1a and raise scene
 * event 0x4f. The row height is read TWICE rather than cached. */
extern int Ov002_Ctx_FindActiveEntryByTag(int tag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int node, int armed);
extern int Ov002_ForwardToSubDc(int event);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int);

extern char *data_ov002_0207f618;

void Ov002_OpenConfirmPrompt(int a, int b) {
    char *ctx = data_ov002_0207f618;

    *(int *)(ctx + 0x178) = 1;
    *(int *)(ctx + 0x17c) = b;
    *(int *)(ctx + 0x184) = a;
    *(short *)(ctx + 0x180) = *(unsigned short *)(ctx + 0x3a);
    *(short *)(ctx + 0x182) = *(unsigned short *)(ctx + 0x3a);

    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(0x1a), 0);
    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x4f));
}
