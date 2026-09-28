void Ov025_Res_BindSecondBlock(int arg0) {
    int n = *(int *)(arg0 + 8);
    *(int *)(arg0 + 0xc) = n + *(int *)(n + 8);
}
