extern int data_ov002_0207fa00;

int Ov002_GetRootField8d18(void) {
    return *(unsigned char *)(*(int *)&data_ov002_0207fa00 + 0x8d18);
}
