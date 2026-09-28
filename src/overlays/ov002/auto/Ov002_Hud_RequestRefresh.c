extern int data_ov002_0207f614;

void Ov002_Hud_RequestRefresh(void) {
    *(int *)(*(int *)&data_ov002_0207f614 + 0x50) = 1;
}
