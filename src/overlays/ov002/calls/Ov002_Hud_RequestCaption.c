/* When a panel is open requests caption 2 with the argument. */

extern int Ov002_GetPanelField018c();
extern int Ov002_RequestCaption();

int Ov002_Hud_RequestCaption(int arg0) {
    if (Ov002_GetPanelField018c() == 0) {
        return 0;
    }
    return Ov002_RequestCaption(2, arg0);
}
