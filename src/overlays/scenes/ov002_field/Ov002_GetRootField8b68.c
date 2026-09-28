/* Tests a bit of the root context's flag byte at +0x8b68. */

extern int data_ov002_0207fa00;

int Ov002_GetRootField8b68(int arg0) {
    return *(unsigned char *)(*(int *)&data_ov002_0207fa00 + 0x8b68) & (1 << arg0);
}
