/* Drags the info panel and ticks the slider when active. */

extern int Ov025_DragInfoPanel();
extern int Ov025_TickSlider();

void Ov025_MissionMenu_TickPanels(int arg0) {
    if (*(int *)(arg0 + 0x158) != 0) {
        Ov025_DragInfoPanel(arg0);
    }
    if (*(int *)(arg0 + 8) == 0) {
        return;
    }
    Ov025_TickSlider(arg0);
}
