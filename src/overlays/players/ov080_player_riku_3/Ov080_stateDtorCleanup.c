/* Tears the character down: frees its resource tables, releases its effect sequences, destroys the
 * root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov080_FreeSubObjectArrayAndTailSlots(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov080_020b9be0;
void Ov080_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c30, obj + 0x910);
    Ov080_FreeSubObjectArrayAndTailSlots(obj);
    Ov022_DestroyRoot(obj);
    data_ov080_020b9be0 = 0;
}
