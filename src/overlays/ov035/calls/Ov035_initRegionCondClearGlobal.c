extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern int LoadGlobalU16At0(void);
extern void Ov035_ReleaseSlotAndChannels(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov035_020b4ca0;
void Ov035_initRegionCondClearGlobal(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c50, obj + 0x910);
    if (LoadGlobalU16At0() != 0x2a)
        Ov035_ReleaseSlotAndChannels(obj);
    Ov022_DestroyRoot(obj);
    data_ov035_020b4ca0 = 0;
}
