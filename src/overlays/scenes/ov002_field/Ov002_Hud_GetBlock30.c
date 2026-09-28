extern int data_ov002_0207f614;

int Ov002_Hud_GetBlock30(void) {
    return *(int *)&data_ov002_0207f614 + 0x30;
}
