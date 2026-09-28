/* Clears a grid slot: updates its item count and the current page's cell, and empties the slot. */

extern void Ov025_AdjustAndSyncSlot(int obj, int val, int delta);

void Ov025_ClearGridSlot(int param_1, int param_2, int param_3, int param_4) {
    int iVar3 = param_2 * 0xa0 + (param_1 + 0x19c4);
    int iVar2 = param_3 + param_4 * 5;
    int iVar1 = *(int *)(iVar3 + iVar2 * 4);
    if (iVar1 == 0) {
        return;
    }
    if (*(int *)(param_1 + 8) == 0) {
        Ov025_AdjustAndSyncSlot(param_1, *(int *)(iVar1 + 0x14), -1);
    }
    if (param_2 == *(int *)(param_1 + 0x18)) {
        *(int *)(param_4 * 200 + param_1 + param_3 * 0x28 + 0x10a0) = 0;
    }
    *(int *)(iVar3 + iVar2 * 4) = 0;
}
