extern int data_ov002_0207f624;

int Ov002_ScenePanel_IsIdle(void) {
    int p = *(int *)&data_ov002_0207f624;
    return p != 0 && *(int *)p == 0;
}
