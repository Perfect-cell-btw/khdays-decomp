extern void BitArray_SetField();
extern int data_0204be18;

void GameState_SetField(unsigned int arg0, unsigned int arg1, unsigned int arg2) {
    BitArray_SetField(data_0204be18 + 0x10, arg0, arg1, arg2);
}
