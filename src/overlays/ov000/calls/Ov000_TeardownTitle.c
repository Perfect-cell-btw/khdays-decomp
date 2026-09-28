extern void *NNSi_FndGetCurrentRootHeap(void);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void Ov000_FreeResourceRecordBuffer(char *p);
extern void FreeAllListNodeSubBuffers(char *p);
extern void FreeFieldAt8(char *p);
extern void Ov000_SweepElements(char *p);
extern void Ov000_ReleaseThreeBuffers(char *p);
extern void Ov000_DestroyAllListObjects(char *p);
extern void Ov000_ReleaseIfMarked(char *p);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_WaitBusy(int a);
extern void TP_CheckError(int a);
extern void ConstReturn1_2(char *p);
extern void G3X_SetHOffset(int off);
extern int data_ov000_0205ac3c;

/* Title/menu teardown: frees the scratch buffer, releases every sub-allocator and the two
 * layout blocks, stops the two sound channels and resets the 3D horizontal offset. */
void Ov000_TeardownTitle(void) {
    char *heap = (char *)NNSi_FndGetCurrentRootHeap();
    if (*(void **)(heap + 0xd000 + 0x110) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(heap + 0xd000 + 0x110));
        *(void **)(heap + 0xd000 + 0x110) = 0;
    }
    Ov000_FreeResourceRecordBuffer(heap + 0x88);
    FreeAllListNodeSubBuffers(heap + 0x94);
    FreeAllListNodeSubBuffers(heap + 0xd0);
    FreeFieldAt8(heap + 0x258 + 0x9400);
    Ov000_SweepElements(heap + 0x10c);
    Ov000_ReleaseThreeBuffers(heap + 0x10c);
    Ov000_DestroyAllListObjects(heap + 0x158);
    Ov000_DestroyAllListObjects(heap + 0x3d8 + 0x4800);
    Ov000_ReleaseIfMarked(heap + 0x158);
    Ov000_ReleaseIfMarked(heap + 0x3d8 + 0x4800);
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    ConstReturn1_2(heap + 0x68);
    G3X_SetHOffset(0);
    data_ov000_0205ac3c = 0;
}
