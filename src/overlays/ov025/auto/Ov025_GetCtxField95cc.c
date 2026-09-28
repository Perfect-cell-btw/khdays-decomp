extern int data_ov025_020b5744;

int Ov025_GetCtxField95cc(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95cc);
}
