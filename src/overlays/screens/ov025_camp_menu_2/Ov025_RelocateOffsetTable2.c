/* Twin of Ov008_RelocateOffsetTable for the 0xe-entry table at param_1+0x174. */
extern int Archive_LoadFile(void *pool, int count);
extern int gOv025MiMiTrBoxPath_2;

void Ov025_RelocateOffsetTable2(int param_1) {
    int i;
    if (*(int *)(param_1 + 0x174) != 0) return;
    *(int *)(param_1 + 0x174) = Archive_LoadFile(&gOv025MiMiTrBoxPath_2, 0xe);
    for (i = 0; i < *(unsigned char *)(*(int *)(param_1 + 0x174)); i++) {
        int base = *(int *)(param_1 + 0x174);
        ((int *)base)[i + 1] += base;
    }
}
