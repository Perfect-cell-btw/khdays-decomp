extern int data_ov002_0207f620;

int Ov002_Panel_GetField10(void) {
    return *(int *)(*(int *)&data_ov002_0207f620 + 0x10);
}
