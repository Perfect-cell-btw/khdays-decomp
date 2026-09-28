int Ov025_Res_GetDataBlock(int arg0) {
    int n = *(int *)(arg0 + 8);
    return n + *(int *)(n + 4);
}
