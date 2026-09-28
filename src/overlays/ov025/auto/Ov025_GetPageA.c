extern int data_ov025_020b5744;

int Ov025_GetPageA(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x959c);
}
