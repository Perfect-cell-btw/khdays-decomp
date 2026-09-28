extern void Ov008_MenuTeardown(char *p);
extern void Ov008_DisableMainWindows(char *self);
extern void Ov008_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern int Ov008_GetCtxBlock9500(void);
extern int Ov008_GetContext(void);
extern void Ov008_SweepElements(int a);
extern void Ov008_DestroyAllListObjects(int a);
extern void Ov008_ReleaseIfMarked(int a);
extern void Ov008_StoreWordAt0x4a50(int a, int b);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);

/* Scene teardown: releases the sub-allocators, unwinds the active object, blanks the three
 * tiled BG screens and resets the 3D horizontal offset. */
void Ov008_TeardownScene(char *self) {
    int a;
    int b;
    Ov008_MenuTeardown(self + 0x98);
    Ov008_DisableMainWindows(self);
    Ov008_FreeResourceRecordBuffer(self + 4);
    FreeAllListNodeSubBuffers(self + 0x4c);
    FreeAllListNodeSubBuffers(self + 0x10);
    a = Ov008_GetCtxBlock9500();
    b = Ov008_GetContext();
    Ov008_SweepElements(a);
    Ov008_DestroyAllListObjects(b);
    Ov008_ReleaseIfMarked(b);
    Ov008_StoreWordAt0x4a50(b, 0);
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
}
