extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov101_DestroyNodesAndFree(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov101_020bc0e0;
void Ov101_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov101_DestroyNodesAndFree(obj);
    Ov022_DestroyRoot(obj);
    data_ov101_020bc0e0 = 0;
}
