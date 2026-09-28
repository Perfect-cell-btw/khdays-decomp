/* Clears one entry of the global slot array (data_0204c22c + 0xc). Returns the array base plus
 * index words, which the ROM leaves in r0 (func_ov002_0206fb74 passes it on). */

extern int data_0204c22c;

int *ClearGlobalArrayInt(int index) {
    int *p = (int *)*(int *)&data_0204c22c + index;

    p[3] = 0;
    return p;
}
