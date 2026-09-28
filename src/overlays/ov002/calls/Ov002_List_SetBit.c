/* Forward the entry at *(global+4) + 0x200 + param_1*4 (and param_2) to BitArray_SetBit. */
extern int BitArray_SetBit(int entry, int arg);
extern int data_ov002_0207fa20;
int Ov002_List_SetBit(int param_1, int param_2) {
    return BitArray_SetBit(*(int *)((char *)&data_ov002_0207fa20 + 4) + 0x200 + param_1 * 4, param_2);
}
