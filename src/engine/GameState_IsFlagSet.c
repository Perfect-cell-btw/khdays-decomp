#pragma thumb on
extern int BitArray_TestBit(int bits, int index);
extern int gGameState;
/* Return whether bit `arg` is set in the bitset at *(gGameState)+0x10. */
int GameState_IsFlagSet(unsigned int arg) {
    if (BitArray_TestBit(gGameState + 0x10, arg) != 0) {
        return 1;
    }
    return 0;
}
