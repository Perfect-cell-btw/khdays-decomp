/* Sweep ctx->items[] (stride 0x10, count at +0x38); for each element whose +0xc
 * word is nonzero, notify Ov025_FreeElementBuffer(ctx, element). base/count reloaded
 * each iteration because the callee may mutate *ctx. Returns the count, which
 * Ov025_SweepElements passes on. */
extern void Ov025_FreeElementBuffer(int ctx, int element);
struct Elem2 { unsigned char _pad[0xc]; int field_c; };
struct Ctx2 { unsigned char _0[0x14]; struct Elem2 *items; unsigned char _1[0x20]; int count; };
int Ov025_SweepFreeElementBuffers(int ctx_) {
    struct Ctx2 *ctx = (struct Ctx2 *)ctx_;
    int i;
    int count;

    for (i = 0; i < (count = ctx->count); i++) {
        if (ctx->items[i].field_c != 0) {
            Ov025_FreeElementBuffer(ctx_, (int)&ctx->items[i]);
        }
    }
    return count;
}
