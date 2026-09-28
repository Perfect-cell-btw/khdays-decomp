extern int data_ov002_0207f600;

void Ov002_Scene_SetFlagBit3(void) {
    int p = *(int *)&data_ov002_0207f600;
    *(int *)p |= 8;
}
