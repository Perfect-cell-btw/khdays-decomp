/* Ov023_ResetEntryTable -- reset the 0x40-entry table at +0x1daf0 of the scene object: run
 * Ov023_ActorRelease over each 0x1a64-byte entry and then wipe the whole 0x69900-byte block.
 * The stride is held in a local because the ROM keeps it in a register across the loop. */
extern void Ov023_ActorRelease(int p);
extern void MI_CpuFill8(void *dst, int value, unsigned int size);
extern int data_ov023_0208a784;

void Ov023_ResetEntryTable(void) {
    int i;
    int off;
    int step = 0x1a64;
    i = 0;
    off = 0;
    do {
        Ov023_ActorRelease(*(int *)(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x1daf0) + off);
        i = i + 1;
        off = off + step;
    } while (i < 0x40);
    MI_CpuFill8((void *)*(int *)(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x1daf0), 0, 0x69900);
}
