/* Ov008_ReleaseRowSurfaces -- ov008 teardown: release the two fixed surfaces (+0x380, +0x488), then each
 * of the twelve 0x108-byte row surfaces at +0x590 whose entry in data_ov008_0208f050 is
 * non-negative, and finally the two command lists at +0x1248 and +0x1270. */
extern void ReleaseField74AndCleanup(int p);
extern void NNS_GfdSetFrmTexVramState(int p);
extern void NNS_GfdSetFrmPlttVramState(int p);
extern int data_ov008_0208f050;

void Ov008_ReleaseRowSurfaces(int obj) {
    int i;
    char *p;
    ReleaseField74AndCleanup(obj + 0x380);
    ReleaseField74AndCleanup(obj + 0x88 + 0x400);
    p = (char *)(obj + 0x590);
    i = 0;
    do {
        if (((int *)&data_ov008_0208f050)[i] >= 0) {
            ReleaseField74AndCleanup((int)p);
        }
        i = i + 1;
        p = p + 0x108;
    } while (i < 0xc);
    NNS_GfdSetFrmTexVramState(obj + 0x248 + 0x1000);
    NNS_GfdSetFrmPlttVramState(obj + 0x270 + 0x1000);
}
