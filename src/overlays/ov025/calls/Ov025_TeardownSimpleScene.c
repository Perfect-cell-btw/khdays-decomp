extern char *Ov025_GetPageA(void);
extern void Ov025_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern int Ov025_GetCtxBlock9500(void);
extern void Ov025_SweepElements(int a);
extern int Ov025_GetContext(void);
extern void Ov025_DestroyAllListObjects(int a);
extern void Ov025_ReleaseIfMarked(int a);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);

/* Scene teardown: releases the two sub-allocators, unwinds the active object, blanks the three
 * tiled BG screens and resets the 3D horizontal offset. */
void Ov025_TeardownSimpleScene(void) {
    char *self = Ov025_GetPageA();
    int obj;
    Ov025_FreeResourceRecordBuffer(self + 4);
    FreeAllListNodeSubBuffers(self + 0x10);
    Ov025_SweepElements(Ov025_GetCtxBlock9500());
    obj = Ov025_GetContext();
    Ov025_DestroyAllListObjects(obj);
    Ov025_ReleaseIfMarked(obj);
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
}
