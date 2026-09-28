extern void FreeAllListNodeSubBuffers(char *p);
extern void Ov025_FreeResourceRecordBuffer(char *p);
extern void Ov025_DestroyMissionList(char *p);
extern int Ov025_GetCtxBlock9500(void);
extern int Ov025_GetCtxBlock954c(void);
extern int Ov025_GetContext(void);
extern int Ov025_GetBlock4a80(void);
extern void Ov025_SweepElements(int a);
extern void Ov025_DestroyAllListObjects(int a);
extern void Ov025_ReleaseIfMarked(int a);
extern void Ov025_ReleaseRowSurfaces(char *p);

/* Field teardown: releases the four sub-allocators and the layout, then unwinds all four cached
 * objects and hands the scene block to the shared unloader. */
void Ov025_TeardownFieldScene(char *self) {
    int a;
    int b;
    int c;
    int d;
    FreeAllListNodeSubBuffers(self + 0x420 + 0x1000);
    FreeAllListNodeSubBuffers(self + 0x5c + 0x1400);
    FreeAllListNodeSubBuffers(self + 0x98 + 0x1400);
    Ov025_FreeResourceRecordBuffer(self + 0xf4 + 0x1400);
    Ov025_DestroyMissionList(self + 0x3fc + 0x1000);
    a = Ov025_GetCtxBlock9500();
    b = Ov025_GetCtxBlock954c();
    c = Ov025_GetContext();
    d = Ov025_GetBlock4a80();
    Ov025_SweepElements(a);
    Ov025_SweepElements(b);
    Ov025_DestroyAllListObjects(c);
    Ov025_ReleaseIfMarked(c);
    Ov025_DestroyAllListObjects(d);
    Ov025_ReleaseIfMarked(d);
    Ov025_ReleaseRowSurfaces(self + 4);
}
