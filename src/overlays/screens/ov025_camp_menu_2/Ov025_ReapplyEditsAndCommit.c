/* Re-apply the pending edits to every entry, then commit the active one.
 * The guard reads the u16 count into an INT first: comparing the u16 load
 * directly lets mwcc prove it non-negative and emit `beq`, while the ROM
 * branches with the signed `ble`. The loop condition still re-reads it. */
extern void Ov025_Elem_SetPos(int owner, int entry, unsigned short a, unsigned short b);
extern void Ov025_TagTracker_InvokeCallback(int owner, int entry);

void Ov025_ReapplyEditsAndCommit(int param_1, int param_2, unsigned short param_3, unsigned short param_4) {
    int i = 0;
    int n = *(unsigned short *)(param_2 + 2);
    if (n > 0) {
        do {
            Ov025_Elem_SetPos(param_1, (*(int **)(param_2 + 0x2c))[i], param_3, param_4);
            i = i + 1;
        } while (i < (int)*(unsigned short *)(param_2 + 2));
    }
    Ov025_TagTracker_InvokeCallback(param_1,
        *(int *)(*(int *)(param_2 + 0x2c) + *(unsigned short *)(param_2 + 4) * 4));
}
