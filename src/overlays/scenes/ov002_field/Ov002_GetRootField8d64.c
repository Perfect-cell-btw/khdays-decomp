/* Returns a word at a fixed offset of the object a global points to. */

extern int data_ov002_0207fa00;

int Ov002_GetRootField8d64(void) {
    return *(int *)(*(int *)&data_ov002_0207fa00 + 0x8d64);
}
