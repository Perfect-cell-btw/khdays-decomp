extern int Ov025_GetPageA();
extern void MI_CpuFill8();

void Ov025_PageA_ResetSmall(int arg0) {
    int x = Ov025_GetPageA(arg0);
    MI_CpuFill8(x, 0, 0xbc);
    *(int *)(x + 0xb4) = 0;
    *(int *)(x + 0xb8) = 0;
    *(short *)(x + 2) = 0;
}
