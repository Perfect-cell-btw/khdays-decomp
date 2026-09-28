extern int data_ov002_0207f99c;

int Ov002_GetSessionField14(void) {
    int p = *(int *)&data_ov002_0207f99c;
    return p == 0 ? 0 : *(int *)(p + 0x14);
}
