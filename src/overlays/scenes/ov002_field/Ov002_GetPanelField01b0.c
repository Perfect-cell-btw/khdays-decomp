/* Returns a word at a fixed offset of the object a global points to. */

extern int data_ov002_0207f614;

int Ov002_GetPanelField01b0(void) {
    return *(int *)(*(int *)&data_ov002_0207f614 + 0x1b0);
}
