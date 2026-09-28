/* Ov008_PanelUpdate -- per-frame update of the ov008 panel: base tick (Ov008_UpdateCommWidgets),
 * then each live sub-widget in turn (obj[0], obj[2], obj[5] gate their updates). */
extern void Ov008_UpdateCommWidgets(void);
extern void Ov008_DragScrollGauge(int *obj);
extern void Ov008_TickMenuScrollInput(int obj);
extern void Ov008_Menu_SetupStateEntry(int obj);

void Ov008_PanelUpdate(int *param_1) {
    Ov008_UpdateCommWidgets();
    if (*param_1 != 0) {
        Ov008_DragScrollGauge(param_1);
    }
    if (param_1[2] != 0) {
        Ov008_TickMenuScrollInput((int)param_1);
    }
    if (param_1[5] == 0) {
        return;
    }
    Ov008_Menu_SetupStateEntry((int)param_1);
}
