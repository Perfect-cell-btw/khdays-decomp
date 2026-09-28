/* Moves a sprite entry by an offset from its base position. */

extern int Ov025_GetEntryBlock2c();
extern void Ov025_ReleaseTwoSlotsEx();

void Ov025_ApplyOffsetSum(int arg0, int arg1, int *arg2) {
    int *p = (int *)Ov025_GetEntryBlock2c(arg0, arg1);
    int local[2];
    local[0] = arg2[0] + p[0];
    local[1] = arg2[1] + p[1];
    Ov025_ReleaseTwoSlotsEx(arg0, arg1, local);
}
