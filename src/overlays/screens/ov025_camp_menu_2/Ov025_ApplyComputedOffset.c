extern int Ov025_GetBlock4a80();
extern int Ov025_FindEntryById();
extern void Ov025_ApplyOffsetSum();

void Ov025_ApplyComputedOffset(int arg0) {
    int a = Ov025_GetBlock4a80();
    int local[2];
    local[0] = 0;
    local[1] = ((*(int *)(arg0 + 0x2c8) * 0x10 - *(int *)(arg0 + 0x2d0)) - 0x28) * 0x1000;
    Ov025_ApplyOffsetSum(a, Ov025_FindEntryById(a, 1), local);
}
