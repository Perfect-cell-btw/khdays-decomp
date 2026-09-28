/* Touch the current root heap, then return the address of Ov008_CommitSelectedPage. */
extern void NNSi_FndGetCurrentRootHeap(void);
extern void Ov008_CommitSelectedPage(void);

void *Ov008_ReturnToCommitPage(void) {
    NNSi_FndGetCurrentRootHeap();
    return (void *)&Ov008_CommitSelectedPage;
}
