/* Clears two halfwords of the game state (+0x196c, +0x196e); returns 1. */

extern int gGameState;

int Ov069_ShiftGlobalHalfword(void) {
    *(unsigned short *)(*(char **)&gGameState + 0x196e) = 0;
    *(unsigned short *)(*(char **)&gGameState + 0x196c) =
        *(unsigned short *)(*(char **)&gGameState + 0x196e);
    return 1;
}
