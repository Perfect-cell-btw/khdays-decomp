extern char *NNSi_FndGetCurrentRootHeap(void);
extern void Ov072_DisposeAndFreeChild(void);
extern void Ov072_ReleaseChildFromGlobal(char *heap);
extern void func_02023ad0(int h);
extern void ReleaseField74AndCleanup(char *p);
extern void FreeAllResourceTables(char *p);
extern void Ov022_DestroyRoot(char *heap);

/* Enemy overlay teardown: drops the model handle, the two animation blocks and the sound block,
 * then hands the heap back to the shared unloader. */
void Ov072_UnloadEnemyOverlay(void) {
    char *heap = NNSi_FndGetCurrentRootHeap();
    Ov072_DisposeAndFreeChild();
    Ov072_ReleaseChildFromGlobal(heap);
    func_02023ad0(*(int *)(heap + 0x2c2c));
    ReleaseField74AndCleanup(heap + 0x2c34);
    ReleaseField74AndCleanup(heap + 0x2d3c);
    FreeAllResourceTables(heap + 0x2e44);
    Ov022_DestroyRoot(heap);
}
