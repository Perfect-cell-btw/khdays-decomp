extern void Ov025_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern int Ov025_GetCtxBlock9500(void);
extern int Ov025_GetContext(void);
extern void Ov025_SweepElements(int a);
extern void Ov025_DestroyAllListObjects(int a);
extern void Ov025_ReleaseIfMarked(int a);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);

/* Scene teardown: releases the sub-allocators, unwinds the active object, blanks the three
 * tiled BG screens and resets the 3D horizontal offset. */
void Ov025_TeardownListScene(char *self) {
    int a;
    int b;
    Ov025_FreeResourceRecordBuffer(self + 0x158);
    FreeAllListNodeSubBuffers(self + 0x1a0);
    FreeAllListNodeSubBuffers(self + 0x164);
    FreeAllListNodeSubBuffers(self + 0x1dc);
    a = Ov025_GetCtxBlock9500();
    b = Ov025_GetContext();
    Ov025_SweepElements(a);
    Ov025_DestroyAllListObjects(b);
    Ov025_ReleaseIfMarked(b);
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
}
