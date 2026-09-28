/* Returns a word at a fixed offset of the object a global points to. */

extern int data_ov002_0207f620;

int Ov002_Panel_GetField10(void) {
    return *(int *)(*(int *)&data_ov002_0207f620 + 0x10);
}
