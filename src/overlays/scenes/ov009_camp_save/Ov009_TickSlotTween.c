/* Pulses the selected save slot's brightness back and forth with a tween. */

#include "nitro/types.h"

typedef struct Ov009TweenFlags {
    unsigned int pad0 : 2;
    unsigned int active : 1;
    unsigned int rest : 29;
} Ov009TweenFlags;

typedef struct Ov009SaveContext {
    u8 pad000[0x21c];
    u8 tween21c[0x18];
    Ov009TweenFlags tweenFlags;
    int tweenDirection;
} Ov009SaveContext;

extern int Ov009_GetContext(void);
extern void Tween_Configure(
    void *tween,
    int mode,
    int from,
    int to,
    int duration
);
extern void Tween_Start(void *tween);
extern void Tween_Sample(void *tween, int *value);
extern void ClampToRange0to16At0x4628(int manager, int value);

void Ov009_TickSlotTween(Ov009SaveContext *ctx)
{
    int value = 0;
    int manager = Ov009_GetContext();

    if (ctx->tweenFlags.active != 0) {
        int direction = ctx->tweenDirection;
        int from;
        int to;

        to = direction != 0 ? 0x2000 : 0x8000;
        from = direction != 0 ? 0x8000 : 0x2000;
        Tween_Configure(ctx->tween21c, 0, from, to, 500);
        Tween_Start(ctx->tween21c);
        ctx->tweenDirection = ctx->tweenDirection == 0;
    } else {
        Tween_Sample(ctx->tween21c, &value);
        ClampToRange0to16At0x4628(manager, value >> 12);
    }
}
