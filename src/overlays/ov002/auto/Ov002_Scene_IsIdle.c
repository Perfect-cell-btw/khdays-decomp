extern int data_ov002_0207f600;

int Ov002_Scene_IsIdle(void) {
    int v = *(int *)*(int *)&data_ov002_0207f600;
    int r = 0;
    if (v & 1) {
        return 0;
    }
    if ((v & 2) == 0) {
        r = 1;
    }
    return r;
}
