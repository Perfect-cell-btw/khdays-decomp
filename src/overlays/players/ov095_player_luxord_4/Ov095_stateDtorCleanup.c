extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov095_ProcessTwoGlobalSlotsThenNotify(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov022_DestroyRoot(int a);
extern int data_ov095_020bcba0;
void Ov095_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov095_ProcessTwoGlobalSlotsThenNotify(obj);
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov002_FreeResourceTables(obj + 0x2c80, obj + 0x910);
    Ov022_DestroyRoot(obj);
    data_ov095_020bcba0 = 0;
}
