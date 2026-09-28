/* Per-frame battle housekeeping: refreshes the root entries (when the replay flag matches) and,
 * when the local player is ready and not paused, sweeps the heap blocks. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov022_RefreshRootEntries(void);
extern int func_ov022_02088338(void);
extern void Ov022_SweepHeapBlocks(void);
extern int data_0204be04;

int func_ov022_02088dec(void) {
    int p = NNSi_FndGetCurrentRootHeap();
    if (*(unsigned char *)&data_0204be04 !=
        ((unsigned int)(*(unsigned char *)(p + 1) << 0x1b) >> 0x1f)) {
        return 0;
    }
    Ov022_RefreshRootEntries();
    if (func_ov022_02088338() == 0) {
        return 0;
    }
    if ((((unsigned int)(*(unsigned char *)p << 0x1e) >> 0x1e) & 1) != 0) {
        return 0;
    }
    Ov022_SweepHeapBlocks();
    return 0;
}
