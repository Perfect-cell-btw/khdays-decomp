extern int Ov002_World_SetFadeLevel();
extern int data_ov002_0207f614;

void Ov002_SetPanelField018c(void) {
    Ov002_World_SetFadeLevel(0x10);
    *(int *)(*(int *)&data_ov002_0207f614 + 0x18c) = 3;
}
