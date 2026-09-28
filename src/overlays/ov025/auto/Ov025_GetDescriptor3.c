extern int data_ov025_020b5744;

int Ov025_GetDescriptor3(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x96a4;
}
