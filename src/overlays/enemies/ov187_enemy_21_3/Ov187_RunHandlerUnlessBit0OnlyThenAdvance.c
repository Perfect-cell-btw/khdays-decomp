/* Two-way dispatch on the low byte of the flags at (param_1)+0x60: run 020cfc30 unless
 * only bit 0 is set (and bit 7 clear), then always run the ov107 update. */

#include "game/enemy_common.h"

extern void Ov187_UnlinkHeldNode(int);
struct hw60_020cfdbc { unsigned short lo : 8; unsigned short hi : 8; };
void Ov187_RunHandlerUnlessBit0OnlyThenAdvance(int param_1) {
    unsigned int lo = ((struct hw60_020cfdbc *)(param_1 + 0x60))->lo;
    if ((lo & 0x80) || !(lo & 1)) Ov187_UnlinkHeldNode(param_1);
    Ov107_AiState_PostTickBase((char *)param_1);
}
