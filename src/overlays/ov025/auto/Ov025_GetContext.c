extern int data_ov025_020b5744;

int Ov025_GetContext(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4);
}
