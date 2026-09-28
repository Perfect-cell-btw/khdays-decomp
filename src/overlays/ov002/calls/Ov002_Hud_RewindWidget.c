/* Rewinds the HUD's main widget and marks it restarted. */

extern int Ov002_RewindWidget();
extern int data_ov002_0207f628;

void Ov002_Hud_RewindWidget(void) {
    int p = *(int *)&data_ov002_0207f628;
    Ov002_RewindWidget(p + 0x1f0, 1);
    *(int *)(p + 0x48) = 1;
}
