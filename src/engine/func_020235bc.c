/* Clears a bit of a global bit array (data_0204be18 + 0x10). */

extern void BitArray_ClearBit();
extern int data_0204be18;

void func_020235bc(int arg0) {
    BitArray_ClearBit(data_0204be18 + 0x10, arg0);
}
