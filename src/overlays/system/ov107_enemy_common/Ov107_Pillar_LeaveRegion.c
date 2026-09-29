/* Pillar +0x2c handler: clears stance bit 0, zeroes the two vectors and leaves the region. */

#include "game/enemy_common.h"

struct T { int a, b, c; };

extern struct T data_02041dc8;

void Ov107_Pillar_LeaveRegion(void *self, int region)
{
    unsigned short *p = (unsigned short *)((char *)self + 0x60);
    unsigned int h = *p;
    unsigned int lo = h & ~0xff00;
    unsigned short hi = (unsigned short)(((h << 0x10) >> 0x18) & ~1);
    struct T local;

    *p = lo | (((unsigned int)hi << 0x18) >> 0x10);

    local = data_02041dc8;
    *(struct T *)((char *)self + 0x1a8) = local;
    *(struct T *)((char *)self + 0xfc) = local;

    Ov107_RemoveChildFromRegion((int)self, region);
}
