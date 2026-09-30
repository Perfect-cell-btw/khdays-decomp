/* Clears a game-state flag (bit array at gGameState + 0x10); the counterpart of
 * GameState_SetFlag. */

extern void BitArray_ClearBit();
extern int gGameState;

void GameState_ClearFlag(int flag) {
    BitArray_ClearBit(gGameState + 0x10, flag);
}
