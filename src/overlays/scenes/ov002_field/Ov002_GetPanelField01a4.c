/* Returns the panel's halfword at +0x1a4. */

extern int data_ov002_0207f614;

unsigned short Ov002_GetPanelField01a4(void) {
    return *(unsigned short *)(*(int *)&data_ov002_0207f614 + 0x1a4);
}
