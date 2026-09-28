/* Tears the character down: frees its resource tables, releases its effect sequences, destroys the
 * root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov097_FreeSubObjectArrayAndTailSlots(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov097_020bc2a0;
void Ov097_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c30, obj + 0x910);
    Ov097_FreeSubObjectArrayAndTailSlots(obj);
    Ov022_DestroyRoot(obj);
    data_ov097_020bc2a0 = 0;
}
