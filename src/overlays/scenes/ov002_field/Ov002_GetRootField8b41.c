extern int data_ov002_0207fa00;

int Ov002_GetRootField8b41(void) {
    return *(unsigned char *)(*(int *)&data_ov002_0207fa00 + 0x8b41);
}
