/* Returns the root context's signed halfword at +0x8bc8. */

extern int data_ov002_0207fa00;

int Ov002_GetRootField8bc8(void) {
    return *(signed short *)(*(int *)&data_ov002_0207fa00 + 0x8bc8);
}
