/* When the background job's thread has finished, frees it and returns its result; otherwise -1. */

extern int OS_IsThreadTerminated();
extern void NNSi_FndFreeFromDefaultHeap();
extern int data_ov025_020b5760;

int Ov025_ReapTerminatedJobResult(void) {
    int r = -1;
    if (*(int *)((char *)&data_ov025_020b5760 + 8) != 0 &&
        OS_IsThreadTerminated(*(int *)((char *)&data_ov025_020b5760 + 8))) {
        r = *(int *)(*(int *)((char *)&data_ov025_020b5760 + 8) + 0x2cc);
        NNSi_FndFreeFromDefaultHeap(*(int *)((char *)&data_ov025_020b5760 + 8));
        *(int *)((char *)&data_ov025_020b5760 + 8) = 0;
    }
    return r;
}
