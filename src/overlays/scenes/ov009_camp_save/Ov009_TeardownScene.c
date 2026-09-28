extern void Ov009_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern int Ov009_GetCtxBlock9500(void);
extern int Ov009_GetContext(void);
extern void Ov009_SweepElements(int a);
extern void Ov009_DestroyAllListObjects(int a);
extern void Ov009_ReleaseIfMarked(int a);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void G3X_SetHOffset(int off);
extern void Scene_RequestPending(int a, int b);

/* Scene teardown: releases the sub-allocators, unwinds the active object, blanks the three
 * tiled BG screens and resets the 3D horizontal offset. */
void Ov009_TeardownScene(char *self) {
    int a;
    int b;
    Ov009_FreeResourceRecordBuffer(self + 0x15c);
    FreeAllListNodeSubBuffers(self + 0x1a4);
    FreeAllListNodeSubBuffers(self + 0x168);
    FreeAllListNodeSubBuffers(self + 0x1e0);
    a = Ov009_GetCtxBlock9500();
    b = Ov009_GetContext();
    Ov009_SweepElements(a);
    Ov009_DestroyAllListObjects(b);
    Ov009_ReleaseIfMarked(b);
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    G3X_SetHOffset(0);
    Scene_RequestPending(1, 0);
}
