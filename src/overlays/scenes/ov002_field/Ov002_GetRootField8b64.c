extern int data_ov002_0207fa00;

int Ov002_GetRootField8b64(void) {
    return *(int *)(*(int *)&data_ov002_0207fa00 + 0x8b64);
}
