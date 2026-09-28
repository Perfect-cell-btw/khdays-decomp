extern int data_ov002_0207f9f8;

int Ov002_GetCueEntry(int arg0) {
    int p = *(int *)&data_ov002_0207f9f8;
    return p == 0 ? 0 : arg0 * 0xc + *(int *)(p + 8);
}
