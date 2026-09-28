/* Read bit 2 of the word pointed to by the ov026 global pointer. */
extern int data_ov026_02091360;
int Ov026_SceneIsActive(void) {
    return *(int *)data_ov026_02091360 & 4;
}
