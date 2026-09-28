extern int data_ov002_0207f62c;

int Ov002_Field_IsActive(void) {
    int p = *(int *)((char *)&data_ov002_0207f62c + 4);
    if (p == 0) {
        return 0;
    }
    return *(int *)(p + 8) != 0;
}
