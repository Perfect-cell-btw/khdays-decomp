/* Scene hook pfnActivate: clears bit 0 and sets bit 1 of the scene flags. */

extern int data_ov025_020b5740;

void Ov025_SceneActivate(void) {
    int p = *(int *)&data_ov025_020b5740;
    *(int *)p = *(int *)p & ~1 | 2;
}
