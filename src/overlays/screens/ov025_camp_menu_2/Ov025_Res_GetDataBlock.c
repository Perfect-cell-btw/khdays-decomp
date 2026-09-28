/* Returns the address of the resource block's data (its header gives the offset). */

int Ov025_Res_GetDataBlock(int arg0) {
    int n = *(int *)(arg0 + 8);
    return n + *(int *)(n + 4);
}
