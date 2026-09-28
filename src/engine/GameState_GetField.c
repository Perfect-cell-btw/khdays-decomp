/* Reads a bit field of the game state's flag array (BitArray_GetField). Returns the field's value.
 */

extern int BitArray_GetField();
extern int data_0204be18;

int GameState_GetField(int arg0, int arg1) {
    return BitArray_GetField(data_0204be18 + 0x10, arg0, arg1);
}
