/* Ov025_PanelUpdate -- per-frame update of the ov025 panel's live sub-widgets
 * (obj[0], obj[2], obj[5] gate their updates). Same shape as Ov008_PanelUpdate. */
extern void Ov025_DragScrollGauge(int *obj);
extern void Ov025_TickMenuScrollInput(int obj);
extern void Ov025_Menu_SetupStateEntry(int obj);

void Ov025_PanelUpdate(int *param_1) {
    if (*param_1 != 0) {
        Ov025_DragScrollGauge(param_1);
    }
    if (param_1[2] != 0) {
        Ov025_TickMenuScrollInput((int)param_1);
    }
    if (param_1[5] == 0) {
        return;
    }
    Ov025_Menu_SetupStateEntry((int)param_1);
}
