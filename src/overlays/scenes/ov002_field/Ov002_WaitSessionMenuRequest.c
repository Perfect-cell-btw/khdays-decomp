/* If the pending flag at heap+0x8d9e is set, clear it and return the deferred
 * handler Ov002_StepSessionMenu; otherwise return 0 (nothing pending). */
extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_StepSessionMenu(void);

int Ov002_WaitSessionMenuRequest(void) {
    int heap = NNSi_FndGetCurrentRootHeap();
    if (*(unsigned char *)(heap + 0x8d9e) != 0) {
        *(unsigned char *)(heap + 0x8d9e) = 0;
        return (int)&Ov002_StepSessionMenu;
    }
    return 0;
}
