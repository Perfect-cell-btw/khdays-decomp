/* Return bit 2 (mask 4) of the chained flag word at (*(&data+4))+0x1c. */
extern int data_ov027_02084360;
int Ov027_SceneIsActive(void) {
    return *(int *)(*(int *)((char *)&data_ov027_02084360 + 4) + 0x1c) & 4;
}
