/* Enables the lock-on selection when it is already active or when a candidate is found. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern int func_ov022_02083f0c(void);
extern void Ov022_SetSelectionEnabled(int arg0);
extern int Ov022_RefreshSelectionCandidates(void);
void func_ov022_02085280(void) {
    int h = NNSi_FndGetCurrentRootHeap();
    func_ov022_02083f0c();
    if ((*(unsigned int *)(h + 4) & 2) != 0) {
        Ov022_SetSelectionEnabled(1);
        return;
    }
    if (!Ov022_RefreshSelectionCandidates()) return;
    Ov022_SetSelectionEnabled(1);
}
