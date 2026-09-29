/* Clears a game-state flag (bit array at data_0204be18 + 0x10); the counterpart of
 * GameState_SetFlag. */

extern void BitArray_ClearBit();
extern int data_0204be18;

void GameState_ClearFlag(int flag) {
    BitArray_ClearBit(data_0204be18 + 0x10, flag);
}
