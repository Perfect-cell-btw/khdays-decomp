/* Tears the character down: releases the charge effect, frees its resource tables, the secondary
 * effect and the emitter, destroys the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov055_ClearFlagAndReleaseChild(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov055_FreeGlobalSlotAndTwoChannels(int a);
extern void Ov055_ReleaseAndFreeField2644(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov055_020b7740;
void Ov055_stateDtorCleanupMulti(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov055_ClearFlagAndReleaseChild(obj);
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov055_FreeGlobalSlotAndTwoChannels(obj);
    Ov055_ReleaseAndFreeField2644(obj);
    Ov022_DestroyRoot(obj);
    data_ov055_020b7740 = 0;
}
