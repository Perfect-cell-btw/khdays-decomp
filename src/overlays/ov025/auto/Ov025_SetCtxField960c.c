extern int data_ov025_020b5744;

void Ov025_SetCtxField960c(void) {
    data_ov025_020b5744 = 1;
    *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x960c) = 0;
}
