/* Mark the current root heap's +8 field and return 0. */
extern int NNSi_FndGetCurrentRootHeap(void);
int Ov005_FinishExit(void) {
    *(int *)(NNSi_FndGetCurrentRootHeap() + 8) = 1;
    return 0;
}
