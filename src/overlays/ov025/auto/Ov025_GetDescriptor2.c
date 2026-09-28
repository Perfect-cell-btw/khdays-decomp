extern int data_ov025_020b5744;

int Ov025_GetDescriptor2(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x9698;
}
