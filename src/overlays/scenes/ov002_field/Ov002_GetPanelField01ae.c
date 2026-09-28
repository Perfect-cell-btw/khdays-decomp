/* Returns a byte of the object a global points to. */

extern int data_ov002_0207f614;

int Ov002_GetPanelField01ae(void) {
    return *(unsigned char *)(*(int *)&data_ov002_0207f614 + 0x1ae);
}
