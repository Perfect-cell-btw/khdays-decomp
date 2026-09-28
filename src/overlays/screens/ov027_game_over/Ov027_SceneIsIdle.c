/* Report whether bit 3 of the +0x1c flags is clear. */
extern int data_ov027_02084360;
int Ov027_SceneIsIdle(void) {
    return (*(int *)((&data_ov027_02084360)[1] + 0x1c) & 8) == 0;
}
