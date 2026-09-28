extern int data_ov002_0207fa20;

int Ov002_GetModuleSlot(int arg0) {
    return *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + arg0 * 4 + 0x17c);
}
