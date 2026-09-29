/* Ov016_Entry_QueryStateReturn8 -- play the entry's SFX and yield 8 frames, ov016. Passes the
 * entry's sound id (@+0x14) and volume (@+0x16) to GameState_GetField; returns 8. */

#include "game/engine.h"

int Ov016_Entry_QueryStateReturn8(char *entry) {
    GameState_GetField(*(unsigned short *)(entry + 0x14), *(unsigned char *)(entry + 0x16));
    return 8;
}
