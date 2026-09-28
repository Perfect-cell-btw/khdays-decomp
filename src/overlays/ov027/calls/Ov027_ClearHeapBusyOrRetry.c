extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov027_GameOverFadeIn(void);
/* Clear the heap's busy bit; if it is still locked (bit 0) report none, else hand back the
 * retry callback. */
int Ov027_ClearHeapBusyOrRetry(void) {
    int heap = NNSi_FndGetCurrentRootHeap();
    int flags = *(int *)(heap + 0x1c) & ~8;
    *(int *)(heap + 0x1c) = flags;
    if ((flags & 1) != 0) {
        return 0;
    }
    return (int)Ov027_GameOverFadeIn;
}
