/* Returns the indexed word of a table inside the object a global points to. */

extern int data_ov002_0207f614;

int Ov002_GetPanelWord0220Idx(int arg0) {
    return *(int *)(*(int *)&data_ov002_0207f614 + arg0 * 4 + 0x220);
}
