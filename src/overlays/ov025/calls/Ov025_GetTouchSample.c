extern void MI_CpuCopy8();

int Ov025_GetTouchSample(int arg0, int arg1) {
    MI_CpuCopy8(arg0 + 0x4a44, arg1, 8);
    return arg1;
}
