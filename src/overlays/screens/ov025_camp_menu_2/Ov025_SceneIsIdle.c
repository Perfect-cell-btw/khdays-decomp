/* Scene hook pfnIsIdle: true while bit 3 of the scene flags is clear. */

extern int data_ov025_020b5740;

int Ov025_SceneIsIdle(void) {
    return (*(int *)*(int *)&data_ov025_020b5740 & 8) == 0;
}
