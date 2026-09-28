/* Whether the panel's state (+0x18c) is outside 9..11. */

extern int data_ov002_0207f614;

int Ov002_GetPanelField018c(void) {
    int r = 1;
    int v = *(int *)(*(int *)&data_ov002_0207f614 + 0x18c);
    if (v < 9) {
        return r;
    }
    if (v <= 0xb) {
        r = 0;
    }
    return r;
}
