extern int Ov002_SceneHidePanel();
extern int Ov002_GetPanelField018c();
extern int data_ov002_0207f614;

void Ov002_Hud_HidePanel(int arg0) {
    Ov002_SceneHidePanel(arg0);
    if (Ov002_GetPanelField018c() != 0) {
        return;
    }
    *(int *)(*(int *)&data_ov002_0207f614 + 0x18c) = 0;
}
