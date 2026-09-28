/* Tears the character down: frees its resource tables and effect nodes, destroys the root object
 * and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov084_DestroyNodesAndFree(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov084_020b9a20;
void Ov084_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov084_DestroyNodesAndFree(obj);
    Ov022_DestroyRoot(obj);
    data_ov084_020b9a20 = 0;
}
