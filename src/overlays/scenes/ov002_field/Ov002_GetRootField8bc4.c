/* Whether the root context's word at +0x8bc4 is set. */

extern int data_ov002_0207fa00;

int Ov002_GetRootField8bc4(void) {
    return *(int *)(*(int *)&data_ov002_0207fa00 + 0x8bc4) != 0;
}
