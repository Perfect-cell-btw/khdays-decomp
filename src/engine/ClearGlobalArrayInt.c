/* Clears one entry of the global slot array (data_0204c22c + 0xc). */

extern int data_0204c22c;

void ClearGlobalArrayInt(int index) {
    *(int *)(*(int *)&data_0204c22c + index * 4 + 0xc) = 0;
}
