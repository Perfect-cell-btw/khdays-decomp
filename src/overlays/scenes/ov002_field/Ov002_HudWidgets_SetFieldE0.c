/* Stores the value at HUD widgets +0xe0, if they exist. */

extern int data_ov002_0207f628;

void Ov002_HudWidgets_SetFieldE0(int arg0) {
    int p = *(int *)&data_ov002_0207f628;
    if (p != 0) {
        *(int *)(p + 0xe0) = arg0;
    }
}
