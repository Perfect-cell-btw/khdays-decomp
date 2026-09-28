extern int data_ov025_020b5740;

void Ov025_SceneActivate(void) {
    int p = *(int *)&data_ov025_020b5740;
    *(int *)p = *(int *)p & ~1 | 2;
}
