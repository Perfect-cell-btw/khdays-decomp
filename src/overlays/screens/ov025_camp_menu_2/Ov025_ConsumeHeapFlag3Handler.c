/* Once the context's ready flag is set, clears it and returns the idle step. */

extern int NNSi_FndGetCurrentRootHeap();
extern void Ov025_GetIdleHandler();

int Ov025_ConsumeHeapFlag3Handler(void) {
    unsigned int *h = (unsigned int *)NNSi_FndGetCurrentRootHeap();
    if ((*h & 8) != 0) {
        *h &= 0xfffffff7;
        return (int)Ov025_GetIdleHandler;
    }
    return 0;
}
