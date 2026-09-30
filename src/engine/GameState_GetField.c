/* Reads a bit field of the game state's flag array (BitArray_GetField). Returns the field's value.
 */

extern int BitArray_GetField();
extern int gGameState;

int GameState_GetField(int arg0, int arg1) {
    return BitArray_GetField(gGameState + 0x10, arg0, arg1);
}
