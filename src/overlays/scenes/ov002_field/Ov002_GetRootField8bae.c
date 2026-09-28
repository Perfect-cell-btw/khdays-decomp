/* Returns a signed byte of the root field object (data_ov002_0207fa00). */

extern int data_ov002_0207fa00;

int Ov002_GetRootField8bae(void) {
    return *(signed char *)(*(int *)&data_ov002_0207fa00 + 0x8bae);
}
