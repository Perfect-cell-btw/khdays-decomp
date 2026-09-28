extern char *data_ov008_02090fac;
extern void Slot_UnlinkIfLinked(int handle, int cell);

/* Rebuilds all 24 cells of both sprite rows from the cached OAM template. */
void Ov008_RebuildSpriteCells(void) {
    char *ui = *(char **)&data_ov008_02090fac;
    int (*rows)[8] = (int (*)[8])(ui + 0xc254);
    int handle = *(int *)(ui + 0xbfb4);
    int i;
    for (i = 0; i < 0x18; i++) {
        Slot_UnlinkIfLinked(handle, rows[i >> 3][i & 7]);
        Slot_UnlinkIfLinked(handle, rows[(i >> 3) + 3][i & 7]);
    }
}
