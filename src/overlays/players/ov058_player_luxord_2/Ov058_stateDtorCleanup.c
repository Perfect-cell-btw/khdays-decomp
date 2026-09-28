/* Tears the character down: releases its effect sequences and attached group, frees its two
 * resource tables, destroys the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov058_ProcessTwoGlobalSlotsThenNotify(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov022_DestroyRoot(int a);
extern int data_ov058_020b7e00;
void Ov058_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov058_ProcessTwoGlobalSlotsThenNotify(obj);
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov002_FreeResourceTables(obj + 0x2c80, obj + 0x910);
    Ov022_DestroyRoot(obj);
    data_ov058_020b7e00 = 0;
}
