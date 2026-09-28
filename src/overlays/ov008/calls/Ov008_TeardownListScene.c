extern void Ov008_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern int Ov008_GetCtxBlock9500(void);
extern int Ov008_GetContext(void);
extern void Ov008_SweepElements(int a);
extern void Ov008_DestroyAllListObjects(int a);
extern void Ov008_ReleaseIfMarked(int a);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);

/* Scene teardown: releases the sub-allocators, unwinds the active object, blanks the three
 * tiled BG screens and resets the 3D horizontal offset. */
void Ov008_TeardownListScene(char *self) {
    int a;
    int b;
    Ov008_FreeResourceRecordBuffer(self + 0x158);
    FreeAllListNodeSubBuffers(self + 0x1a0);
    FreeAllListNodeSubBuffers(self + 0x164);
    FreeAllListNodeSubBuffers(self + 0x1dc);
    a = Ov008_GetCtxBlock9500();
    b = Ov008_GetContext();
    Ov008_SweepElements(a);
    Ov008_DestroyAllListObjects(b);
    Ov008_ReleaseIfMarked(b);
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
}
