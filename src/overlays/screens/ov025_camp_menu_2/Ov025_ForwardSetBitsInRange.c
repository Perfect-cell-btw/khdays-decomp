/* Marks every item in the bitset as seen (game-state flags 0x37ca onwards). */

extern int Ov025_TestBitInBitset();
extern void GameState_SetFlag();

void Ov025_ForwardSetBitsInRange(int arg0) {
    int i = 1;
    do {
        if (Ov025_TestBitInBitset(arg0, i)) GameState_SetFlag(i + 0x37c9);
        i++;
    } while (i < 0x277);
}
