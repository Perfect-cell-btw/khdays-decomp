extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov053_ReleaseChildFromGlobal(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov053_020b7e60;
void Ov053_initTwoRegionsClearGlobal(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov002_FreeResourceTables(obj + 0x2c80, obj + 0x910);
    Ov053_ReleaseChildFromGlobal(obj);
    Ov022_DestroyRoot(obj);
    data_ov053_020b7e60 = 0;
}
