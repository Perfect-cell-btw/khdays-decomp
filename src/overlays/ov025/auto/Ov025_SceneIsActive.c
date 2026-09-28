/* Scene hook pfnIsActive: returns bit 2 of the scene flags. */

extern int data_ov025_020b5740;

int Ov025_SceneIsActive(void) {
    return *(int *)*(int *)&data_ov025_020b5740 & 4;
}
