/* Tears the character down: frees its two resource tables, releases its effect sub-block, destroys
 * the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov073_ReleaseChildFromGlobal(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov073_020ba540;
void Ov073_initTwoRegionsClearGlobal(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    Ov002_FreeResourceTables(obj + 0x2c2c, obj + 0x910);
    Ov002_FreeResourceTables(obj + 0x2c80, obj + 0x910);
    Ov073_ReleaseChildFromGlobal(obj);
    Ov022_DestroyRoot(obj);
    data_ov073_020ba540 = 0;
}
