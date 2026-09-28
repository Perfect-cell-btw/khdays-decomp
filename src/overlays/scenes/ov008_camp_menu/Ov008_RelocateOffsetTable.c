/* Lazily allocate the 0xe-entry table at param_1+0x58, then relocate each entry's
 * stored offset at +4 to an absolute pointer by adding the table base. */
extern int Archive_LoadFile(void *pool, int count);
extern int data_ov008_0209086c;

void Ov008_RelocateOffsetTable(int param_1) {
    int i;
    if (*(int *)(param_1 + 0x58) != 0) return;
    *(int *)(param_1 + 0x58) = Archive_LoadFile(&data_ov008_0209086c, 0xe);
    for (i = 0; i < *(unsigned char *)(*(int *)(param_1 + 0x58)); i++) {
        int base = *(int *)(param_1 + 0x58);
        ((int *)base)[i + 1] += base;
    }
}
