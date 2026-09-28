/* Tears the character down: frees its resource tables, releases its effect slot and channels unless
 * in the mode that has none, destroys the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern int LoadGlobalU16At0(void);
extern void Ov054_ReleaseSlotAndChannels(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov054_020b74a0;
void Ov054_initRegionCondClearGlobal(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c50, obj + 0x910);
    if (LoadGlobalU16At0() != 0x2a)
        Ov054_ReleaseSlotAndChannels(obj);
    Ov022_DestroyRoot(obj);
    data_ov054_020b74a0 = 0;
}
