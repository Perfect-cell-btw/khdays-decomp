/* Returns the entry count of the resource block (+8). */

int Ov025_Res_GetCount(int arg0) {
    return *(unsigned short *)(*(int *)(arg0 + 8) + 0xe);
}
