extern int Ov002_PanelActivateSlot();
extern int data_ov002_0207f614;

void Ov002_Hud_ActivatePanelSlot(void) {
    int p = *(int *)&data_ov002_0207f614;
    *(short *)(p + 0x1a4) = Ov002_PanelActivateSlot();
    *(char *)(p + 0x1ac) = 4;
    *(int *)(p + 0x1a8) = 0;
}
