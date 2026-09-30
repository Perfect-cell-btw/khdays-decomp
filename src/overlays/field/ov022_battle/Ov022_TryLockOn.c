/* Locks on (Ov022_SetSelectionEnabled(1)) when the selection is already active (bit 1 of +4 of
 * the root block) or when Ov022_RefreshSelectionCandidates finds a candidate in reach.
 * Ov022_ReadSelectionInput calls it when R is pressed twice within 9 game frames. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern int func_ov022_02083f0c(void);
extern void Ov022_SetSelectionEnabled(int arg0);
extern int Ov022_RefreshSelectionCandidates(void);
void Ov022_TryLockOn(void) {
    int h = NNSi_FndGetCurrentRootHeap();
    func_ov022_02083f0c();
    if ((*(unsigned int *)(h + 4) & 2) != 0) {
        Ov022_SetSelectionEnabled(1);
        return;
    }
    if (!Ov022_RefreshSelectionCandidates()) return;
    Ov022_SetSelectionEnabled(1);
}
