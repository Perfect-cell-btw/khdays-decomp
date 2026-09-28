/* Requests a HUD refresh unless the reason is 8. */

extern int Ov002_Hud_RequestRefresh();

void Ov002_Hud_RefreshUnless8(int arg0) {
    if (arg0 == 8) {
        return;
    }
    Ov002_Hud_RequestRefresh();
}
