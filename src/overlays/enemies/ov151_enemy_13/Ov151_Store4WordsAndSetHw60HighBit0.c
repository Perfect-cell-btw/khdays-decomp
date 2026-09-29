/* Moves the node and re-lays it out, stores the four words at +0x394 and sets bit 0 of the high
 * byte of its flags (+0x60). */

#include "game/enemy_common.h"

struct w4 { int a, b, c, d; };

void Ov151_Store4WordsAndSetHw60HighBit0(int this_, int arg1, struct w4 *src) {
    unsigned short *p;
    unsigned int h;
    Ov107_MoveNodeAndRelayout((Actor *)this_, (VecFx32 *)arg1);
    *(struct w4 *)(this_ + 0x394) = *src;
    p = (unsigned short *)(this_ + 0x60);
    h = *p;
    *p = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
}
