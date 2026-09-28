/* Ov008_TickTitleFade -- Ov008_TickTitleFade (164 B, 5 relocs).
 * Ticks the title-menu "fade" SRT tween (a 0x18-byte object at ctx+0x218). Fetches the active
 * widget once (Ov008_GetContext). When bit 2 of ctx->flags230 is set it (re)starts the tween --
 * toggling between 0x2000 and 0x8000 over 500 units depending on ctx->field234 -- steps it, and
 * flips field234. Otherwise it samples the current tween value and applies it (>>12, fixed->int)
 * to the widget via ClampToRange0to16At0x4628. */
typedef unsigned char  u8;

typedef struct Ov008FadeCtx {
    u8  pad_0000[0x218];
    u8  fade[0x18];            /* 0x218: SRT/tween object */
    unsigned f230_lo   : 2;    /* 0x230 */
    unsigned f230_bit2 : 1;
    unsigned f230_hi   : 29;
    int field234;             /* 0x234: toggle direction */
} Ov008FadeCtx;

typedef struct Obj Obj;

extern Obj *Ov008_GetContext(void);
extern void Tween_Configure(void *fade, int mode, int from, int to, int dur);
extern void Tween_Start(void *fade);
extern void Tween_Sample(void *fade, int *out);
extern void ClampToRange0to16At0x4628(Obj *o, int v);

void Ov008_TickTitleFade(Ov008FadeCtx *ctx)
{
    int  val = 0;
    Obj *w = Ov008_GetContext();

    if (ctx->f230_bit2) {
        Tween_Configure(&ctx->fade, 0,
                      ctx->field234 ? 0x8000 : 0x2000,
                      ctx->field234 ? 0x2000 : 0x8000, 0x1f4);
        Tween_Start(&ctx->fade);
        ctx->field234 = (ctx->field234 == 0);
    } else {
        Tween_Sample(&ctx->fade, &val);
        ClampToRange0to16At0x4628(w, val >> 12);
    }
}
