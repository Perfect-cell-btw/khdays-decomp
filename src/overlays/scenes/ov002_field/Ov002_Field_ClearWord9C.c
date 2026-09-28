extern int data_ov002_0207f62c;

void Ov002_Field_ClearWord9C(void) {
    *(int *)(*(int *)((char *)&data_ov002_0207f62c + 4) + 0x9c) = 0;
}
