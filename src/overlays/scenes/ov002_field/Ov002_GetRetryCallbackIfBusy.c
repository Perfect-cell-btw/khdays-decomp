extern unsigned short *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_PollSessionWaiters(void);
/* Hand back the retry callback only while the heap's bit 1 is set. */
int Ov002_GetRetryCallbackIfBusy(void) {
    int cb = 0;
    if ((*NNSi_FndGetCurrentRootHeap() & 2) > 0) {
        cb = (int)Ov002_PollSessionWaiters;
    }
    return cb;
}
