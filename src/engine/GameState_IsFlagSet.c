#pragma thumb on
extern int BitArray_TestBit(int bits, int index);
extern int data_0204be18;
/* Return whether bit `arg` is set in the bitset at *(data_0204be18)+0x10. */
int GameState_IsFlagSet(unsigned int arg) {
    if (BitArray_TestBit(data_0204be18 + 0x10, arg) != 0) {
        return 1;
    }
    return 0;
}
