extern char *Ov025_GetPageA(void);
extern void Ov025_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern void Ov025_SweepElements(int a);
extern void Ov025_DestroyAllListObjects(int a);
extern void Ov025_ReleaseIfMarked(int a);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);
extern char *Ov025_GetCueRequest(void);

/* List screen teardown: releases the two row allocators and the layout, unwinds the two cached
 * objects, blanks the three tiled BG screens and clears the pending entry. */
void Ov025_TeardownListScreen(void) {
    char *self = Ov025_GetPageA();
    Ov025_FreeResourceRecordBuffer(self + 0x78);
    Ov025_FreeResourceRecordBuffer(self + 0x6c);
    FreeAllListNodeSubBuffers(self + 0x84);
    Ov025_SweepElements(*(int *)(self + 0xc4));
    Ov025_DestroyAllListObjects(*(int *)(self + 0xc8));
    Ov025_ReleaseIfMarked(*(int *)(self + 0xc8));
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
    *(int *)(Ov025_GetCueRequest() + 0xc) = 0;
}
