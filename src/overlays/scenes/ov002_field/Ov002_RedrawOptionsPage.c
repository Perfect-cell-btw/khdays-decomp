typedef struct {
    unsigned pad : 2;
    unsigned visible : 1;
} PageFlags;

extern void Ov002_PlayCaptionCues(int a, int b);
extern int Ov002_Ctx_FindActiveEntryByTag(int id);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int handle, int a);
extern int Ov002_ForwardToSubDc(int id);
extern void Ov002_ForwardToSubDc_2(int);
extern void Ov002_ForwardToSubDc_5(int a);
extern char *data_ov002_0207f62c;

/* Redraws the options page while it is visible: mode 2 only refreshes the footer, every other
 * mode also rebuilds the two toggles and their labels. */
void Ov002_RedrawOptionsPage(void) {
    char *page = (&data_ov002_0207f62c)[1];
    if (((PageFlags *)(page + 0x70))->visible == 0) {
        return;
    }
    *(int *)(page + 8) = 0;
    if (*(int *)(page + 0xc) != 2) {
        Ov002_PlayCaptionCues(1, 1);
        Ov002_PlayCaptionCues(0, 0);
        Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(8), 0);
        Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(0xb), 0);
        Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x5e1));
        Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x5ed));
    }
    Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x5e3));
    Ov002_ForwardToSubDc_5(1);
}
