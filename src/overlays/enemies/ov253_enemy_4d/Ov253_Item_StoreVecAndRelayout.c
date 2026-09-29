/* Stores the vector (+0x38c), re-lays the node out and sets flags60 bit 8. */

#include "game/enemy_common.h"

struct w3 { int a, b, c; };

void Ov253_Item_StoreVecAndRelayout(int this_, int arg1, struct w3 *src) {
    unsigned short *p;
    unsigned int h;
    *(struct w3 *)(this_ + 0x38c) = *src;
    Ov107_MoveNodeAndRelayout((Actor *)this_, (VecFx32 *)arg1);
    p = (unsigned short *)(this_ + 0x60);
    h = *p;
    *p = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
}
