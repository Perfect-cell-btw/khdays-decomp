extern int data_ov002_0207fa20;

int Ov002_GetModuleScale(void) {
    return *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + 0x64);
}
