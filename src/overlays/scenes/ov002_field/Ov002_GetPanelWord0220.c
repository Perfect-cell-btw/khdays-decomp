/* Sets the indexed panel gauge (+0x220 handles) to the value with the default style (7). */

extern int data_ov002_0207f614;
extern int Ov002_SetGaugeValueDefault();

int Ov002_GetPanelWord0220(int arg0, int arg1) {
    return Ov002_SetGaugeValueDefault(*(int *)(*(int *)&data_ov002_0207f614 + arg0 * 4 + 0x220), arg1, 7);
}
