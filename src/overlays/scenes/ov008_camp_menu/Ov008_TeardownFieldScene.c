extern void FreeAllListNodeSubBuffers(char *p);
extern void Ov008_FreeResourceRecordBuffer(char *p);
extern void Ov008_DestroyMissionList(char *p);
extern int Ov008_GetCtxBlock9500(void);
extern int Ov008_GetCtxBlock954c(void);
extern int Ov008_GetContext(void);
extern int Ov008_GetCtxBlock4a80(void);
extern void Ov008_SweepElements(int a);
extern void Ov008_DestroyAllListObjects(int a);
extern void Ov008_ReleaseIfMarked(int a);
extern void Ov008_ReleaseRowSurfaces(char *p);

/* Field teardown: releases the four sub-allocators and the layout, then unwinds all four cached
 * objects and hands the scene block to the shared unloader. */
void Ov008_TeardownFieldScene(char *self) {
    int a;
    int b;
    int c;
    int d;
    FreeAllListNodeSubBuffers(self + 0x420 + 0x1000);
    FreeAllListNodeSubBuffers(self + 0x5c + 0x1400);
    FreeAllListNodeSubBuffers(self + 0x98 + 0x1400);
    Ov008_FreeResourceRecordBuffer(self + 0xf4 + 0x1400);
    Ov008_DestroyMissionList(self + 0x3fc + 0x1000);
    a = Ov008_GetCtxBlock9500();
    b = Ov008_GetCtxBlock954c();
    c = Ov008_GetContext();
    d = Ov008_GetCtxBlock4a80();
    Ov008_SweepElements(a);
    Ov008_SweepElements(b);
    Ov008_DestroyAllListObjects(c);
    Ov008_ReleaseIfMarked(c);
    Ov008_DestroyAllListObjects(d);
    Ov008_ReleaseIfMarked(d);
    Ov008_ReleaseRowSurfaces(self + 4);
}
