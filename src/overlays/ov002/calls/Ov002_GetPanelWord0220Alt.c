/* Forward the table entry (*global)[param_1] + 0x220 (and param_2) to Ov002_SetGaugeSlotShown. */
extern int Ov002_SetGaugeSlotShown(int entry, int arg);
extern int data_ov002_0207f614;

int Ov002_GetPanelWord0220Alt(int param_1, int param_2) {
    return Ov002_SetGaugeSlotShown(*(int *)(*(int *)&data_ov002_0207f614 + param_1 * 4 + 0x220), param_2);
}
