/* Returns the address of a block inside the object a global points to. */

extern int data_ov002_0207f614;

int Ov002_Hud_GetBlock24(void) {
    return *(int *)&data_ov002_0207f614 + 0x24;
}
