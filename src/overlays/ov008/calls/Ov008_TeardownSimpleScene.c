extern char *Ov008_GetMenuContext(void);
extern void Ov008_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern int Ov008_GetCtxBlock9500(void);
extern void Ov008_SweepElements(int a);
extern int Ov008_GetContext(void);
extern void Ov008_DestroyAllListObjects(int a);
extern void Ov008_ReleaseIfMarked(int a);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);

/* Scene teardown: releases the two sub-allocators, unwinds the active object, blanks the three
 * tiled BG screens and resets the 3D horizontal offset. */
void Ov008_TeardownSimpleScene(void) {
    char *self = Ov008_GetMenuContext();
    int obj;
    Ov008_FreeResourceRecordBuffer(self + 4);
    FreeAllListNodeSubBuffers(self + 0x10);
    Ov008_SweepElements(Ov008_GetCtxBlock9500());
    obj = Ov008_GetContext();
    Ov008_DestroyAllListObjects(obj);
    Ov008_ReleaseIfMarked(obj);
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
}
