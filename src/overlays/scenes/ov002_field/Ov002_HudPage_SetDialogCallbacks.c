/* Stores the two dialog callbacks at HUD page +0x1a8/+0x1ac, if the page exists. */

extern int data_ov002_0207f9fc;

void Ov002_HudPage_SetDialogCallbacks(int arg0, int arg1) {
    int p = *(int *)&data_ov002_0207f9fc;
    if (p != 0) {
        *(int *)(p + 0x1a8) = arg0;
        *(int *)(p + 0x1ac) = arg1;
    }
}
