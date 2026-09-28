/* When a HUD panel is active sets its secondary flag. */

extern int Ov002_GetPanelField018c();
extern int Ov002_PanelSetSecondaryFlag();
extern int data_ov002_0207f614;

void Ov002_Hud_SetSecondaryFlag(int arg0) {
    if (*(int *)&data_ov002_0207f614 == 0) {
        return;
    }
    if (Ov002_GetPanelField018c() == 0) {
        return;
    }
    Ov002_PanelSetSecondaryFlag(arg0);
}
