/* Marks a pending join of the member and posts the join request (message 4, kind 1). */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct { u16 f0; u8 f2; u8 f3; } LocalBuf;

void Ov107_Region_RequestJoin(char *self, char *other) {
    LocalBuf buf = {0, 0, 0};

    *(u32 *)(self + 0xf8) = (*(u32 *)(self + 0xf8) & ~0xf) | 1;
    *(char **)(self + 0xfc) = other;

    buf.f0 = *(u16 *)(self + 2);
    buf.f2 = 1;
    buf.f3 = (u8)*(u16 *)(other + 2);

    MsgQueue_Post(4, &buf, 4);

    *(u32 *)(other + 0x40) &= ~4;
}
