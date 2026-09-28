/* Tears the character down: releases its effect sequences and attached group, frees its two
 * resource tables, destroys the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov078_ProcessTwoGlobalSlotsThenNotify(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov022_DestroyRoot(int a);
extern int data_ov078_020ba4e0;
void Ov078_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov078_ProcessTwoGlobalSlotsThenNotify(obj);
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov002_FreeResourceTables(obj + 0x2c80, obj + 0x910);
    Ov022_DestroyRoot(obj);
    data_ov078_020ba4e0 = 0;
}
