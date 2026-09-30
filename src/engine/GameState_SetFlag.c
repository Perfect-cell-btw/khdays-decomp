/* Sets a flag of the game state's flag array (BitArray_SetBit). */

extern int gGameState;
extern int BitArray_SetBit();

int GameState_SetFlag(int arg0) {
    return BitArray_SetBit(*(int *)&gGameState + 0x10, arg0);
}
