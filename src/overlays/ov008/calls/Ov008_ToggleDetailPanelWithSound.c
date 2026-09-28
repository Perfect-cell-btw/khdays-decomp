extern void Ov008_Menu_ToggleDetailPanel(int);
extern void PlaySound(int, int);
void Ov008_ToggleDetailPanelWithSound(void)
{
    Ov008_Menu_ToggleDetailPanel(1);
    PlaySound(0, 1);
}
