/* Counts the timer down; then installs the branch step. */

extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov145_BranchInvokeOrCopySlotThenAdvance(void);

void Ov145_AiCountdownThenBranch(char *a) {
    char *p = *(char **)a;
    char *q = *(char **)(a + 4);
    int delta = *(int *)(q + 0x40) - *(int *)(p + 0x2c);
    *(int *)(q + 0x40) = delta;
    if (delta > 0) return;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov145_BranchInvokeOrCopySlotThenAdvance);
}
