extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern int LoadGlobalU16At0(void);
extern void Ov091_ReleaseSlotAndChannels(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov091_020bc240;
void Ov091_initRegionCondClearGlobal(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c50, obj + 0x910);
    if (LoadGlobalU16At0() != 0x2a)
        Ov091_ReleaseSlotAndChannels(obj);
    Ov022_DestroyRoot(obj);
    data_ov091_020bc240 = 0;
}
