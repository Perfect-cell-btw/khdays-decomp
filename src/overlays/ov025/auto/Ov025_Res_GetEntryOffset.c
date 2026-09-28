int Ov025_Res_GetEntryOffset(int arg0, int arg1) {
    return *(int *)(*(int *)(arg0 + 8) + arg1 * 4 + 0x10);
}
