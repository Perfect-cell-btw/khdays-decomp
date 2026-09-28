typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

/* Same Tween/TweenFlags shape already established by the callers in the tree
 * (e.g. src/overlays/ov008/calls/Ov008_TickInfoWindowTransition.c, which declares this
 * exact function as `extern void Tween_Sample(Tween *tween, s32 *value);`,
 * and src/overlays/ov005/calls/Ov005_InitResultResources.c /
 * Ov005_UpdateRewardPosition.c with the identical field layout). */
typedef struct TweenFlags {
    u32 started : 1;
    u32 paused : 1;
    u32 finished : 1;
    u32 reserved : 29;
} TweenFlags;

typedef struct Tween {
    s32 mode;           /* easing curve id, see Fx_Tween */
    s32 duration;
    s32 from;
    s32 to;
    long long startTick; /* running: tick the tween started at.
                           * paused: the frozen elapsed tick count itself. */
    TweenFlags flags;
} Tween;

extern long long OS_GetTick(void);                     /* 64-bit tick counter */
extern int func_02020368(u64 value, u32 divisor, int mode); /* runtime 64/32 divide */
extern s32 Fx_Tween(s32 start, s32 end, u32 elapsed, u32 duration, u32 curve);

/* Sample a tween's current value. Does nothing if it hasn't been started.
 * Once finished, keeps reporting the end value. While paused, the elapsed
 * time is read straight from startTick instead of measured against "now". */
void Tween_Sample(Tween *tween, s32 *value)
{
    u32 elapsed;

    if (!tween->flags.started) {
        return;
    }

    if (!tween->flags.finished) {
        u32 duration;

        if (!tween->flags.paused) {
            elapsed = func_02020368(
                (u64)(OS_GetTick() - tween->startTick) << 6, 0x82ea, 0);
        } else {
            elapsed = func_02020368((u64)tween->startTick << 6, 0x82ea, 0);
        }
        duration = tween->duration;
        if (elapsed >= duration) {
            tween->flags.finished = 1;
            elapsed = duration;
        }
    } else {
        elapsed = tween->duration;
    }

    if (value != 0) {
        *value = Fx_Tween(tween->from, tween->to, elapsed, tween->duration,
                                tween->mode);
    }
}
