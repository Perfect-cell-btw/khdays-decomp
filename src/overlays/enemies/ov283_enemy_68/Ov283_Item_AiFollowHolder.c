/* While held (action 1) follows the holder's hand position and rotation. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef struct { int a, b, c, d; } T4;
typedef struct { T4 t; char pad[0x28 - 16]; unsigned char flag; } S;

typedef struct {
    void *f0;
    void *f1;
} Ctx;

typedef struct {
    void *field_00;
    Ctx *ctx;
} Self;

extern int Srt_SetRotationQuat(S *dst, S *src);

void Ov283_Item_AiFollowHolder(Self *self) {
    Ctx *ctx = self->ctx;

    if (*(s8 *)((char *)ctx->f0 + 0x1c6) != 1) {
        return;
    }
    if (ctx->f1 == 0) {
        return;
    }

    Ov107_MoveNodeAndRelayout((Actor *)((char *)ctx->f0), (VecFx32 *)((char *)ctx->f1 + 0x14));
    Srt_SetRotationQuat((S *)((char *)ctx->f0 + 0xa0), (S *)((char *)ctx->f1 + 4));
}
