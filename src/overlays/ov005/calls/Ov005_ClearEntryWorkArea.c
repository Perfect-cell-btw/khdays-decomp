/* Ov005_ClearEntryWorkArea -- clear the entry's 0x600-byte work area, ov005. Resolves the
 * area via Ov005_FindResultRowBuffer(sel, 0) then 16-bit clears it. */
extern void *Ov005_FindResultRowBuffer(int sel, int);
extern void MIi_CpuClear16(int val, void *dst, int size);
void Ov005_ClearEntryWorkArea(int sel) {
    void *area = Ov005_FindResultRowBuffer(sel, 0);
    MIi_CpuClear16(0, area, 0x600);
}
