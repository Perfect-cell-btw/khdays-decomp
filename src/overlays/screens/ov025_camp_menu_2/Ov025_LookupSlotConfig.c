/* Returns the configured slot of a code (and its index), or 0 when it has none. */

extern int Ov025_MapCodeToSlotIndex();
extern int data_ov025_020b5744;

int Ov025_LookupSlotConfig(int arg0, int *arg1) {
    int idx = Ov025_MapCodeToSlotIndex(arg0);
    int r = 0;
    if (idx != -1)
        r = *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + idx * 4 + 0x95a4);
    if (arg1 != 0) *arg1 = idx;
    return r;
}
