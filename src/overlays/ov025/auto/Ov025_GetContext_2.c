extern int data_ov025_020b574c;

int Ov025_GetContext_2(void) {
    return *(int *)((char *)&data_ov025_020b574c + 4);
}
