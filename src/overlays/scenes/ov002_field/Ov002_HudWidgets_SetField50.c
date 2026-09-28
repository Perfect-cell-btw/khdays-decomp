/* Stores the value at HUD widgets +0x50, if they exist. */

extern int data_ov002_0207f628;

void Ov002_HudWidgets_SetField50(int arg0) {
    int p = *(int *)&data_ov002_0207f628;
    if (p != 0) {
        *(int *)(p + 0x50) = arg0;
    }
}
