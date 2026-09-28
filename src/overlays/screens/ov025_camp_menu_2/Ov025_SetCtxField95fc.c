extern int Ov025_EnableBothHalves();
extern int data_ov025_020b5744;

void Ov025_SetCtxField95fc(int arg0) {
    Ov025_EnableBothHalves(arg0);
    *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x95fc) = arg0;
}
