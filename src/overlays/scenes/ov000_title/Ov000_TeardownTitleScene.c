extern char *NNSi_FndGetCurrentRootHeap(void);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_WaitBusy(int a);
extern void TP_CheckError(int a);
extern void Obj_Release(char *p);
extern void ConstReturn1_2(char *p);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void ReleaseField74AndCleanup(char *p);
extern int func_02024e5c(void);
extern void GameState_SetField(int id, int a, unsigned int b);
extern int data_ov000_0205ac20;

/* Title teardown: stops the two sound channels, releases the layout and the animation block
 * (unless the "keep" flag is set), frees the scratch buffer and reports the exit reason. */
void Ov000_TeardownTitleScene(void) {
    char *heap = NNSi_FndGetCurrentRootHeap();
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    if (*(int *)(heap + 0x4000 + 0xc40) == 0) {
        Obj_Release(heap + 0x1b0);
    }
    ConstReturn1_2(heap + 0x3e8 + 0x4800);
    NNSi_FndFreeFromDefaultHeap(*(void **)(heap + 0x14c));
    ReleaseField74AndCleanup(heap + 0xc);
    GameState_SetField(0x2011, 3, (unsigned short)func_02024e5c());
    data_ov000_0205ac20 = 0;
}
