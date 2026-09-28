/* Tears the character down: releases the charge effect, frees its resource tables, the secondary
 * effect and the emitter, destroys the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov036_ClearFlagAndReleaseChild(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov036_FreeGlobalSlotAndTwoChannels(int a);
extern void Ov036_ReleaseAndFreeField2644(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov036_020b4f40;
void Ov036_stateDtorCleanupMulti(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov036_ClearFlagAndReleaseChild(obj);
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov036_FreeGlobalSlotAndTwoChannels(obj);
    Ov036_ReleaseAndFreeField2644(obj);
    Ov022_DestroyRoot(obj);
    data_ov036_020b4f40 = 0;
}
