extern int data_ov025_020b574c;
extern int data_ov025_020b4a78;

int Ov025_HandlerB_GetField0C(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b4a78 + *(int *)((char *)&data_ov025_020b574c + 4) * 8) + 0xc);
}
