extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov092_ClearFlagAndReleaseChild(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov092_FreeGlobalSlotAndTwoChannels(int a);
extern void Ov092_ReleaseAndFreeField2644(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov092_020bc4e0;
void Ov092_stateDtorCleanupMulti(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov092_ClearFlagAndReleaseChild(obj);
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov092_FreeGlobalSlotAndTwoChannels(obj);
    Ov092_ReleaseAndFreeField2644(obj);
    Ov022_DestroyRoot(obj);
    data_ov092_020bc4e0 = 0;
}
