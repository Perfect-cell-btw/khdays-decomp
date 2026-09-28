extern int data_ov002_0207f62c;

int Ov002_GetMissionProgress(void) {
    return *(int *)((char *)&data_ov002_0207f62c + 4) + 0x188;
}
