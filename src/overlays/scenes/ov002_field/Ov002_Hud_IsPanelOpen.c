/* Whether the HUD panel's state (+0x18c) is between 1 and 8 (open). */

extern int data_ov002_0207f614;

int Ov002_Hud_IsPanelOpen(void) {
    int v = *(int *)(*(int *)&data_ov002_0207f614 + 0x18c);
    if (v >= 1 && v <= 8) {
        return 1;
    }
    return 0;
}
