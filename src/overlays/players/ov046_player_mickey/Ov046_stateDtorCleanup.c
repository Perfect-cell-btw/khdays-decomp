extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov046_DestroyNodesAndFree(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov046_020b4b40;
void Ov046_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov046_DestroyNodesAndFree(obj);
    Ov022_DestroyRoot(obj);
    data_ov046_020b4b40 = 0;
}
