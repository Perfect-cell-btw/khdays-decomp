extern int data_ov002_0207fa10;

void Ov002_SetLinkModeAndValue(int arg0, int arg1) {
    int base = *(int *)&data_ov002_0207fa10;
    *(char *)(base + 0x2298) = arg0;
    *(int *)(base + 0x2294) = arg1;
}
