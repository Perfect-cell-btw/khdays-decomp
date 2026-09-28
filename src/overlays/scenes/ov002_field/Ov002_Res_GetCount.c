/* The resource's entry count (header +0xe). */

int Ov002_Res_GetCount(int arg0) {
    return *(unsigned short *)(*(int *)(arg0 + 8) + 0xe);
}
