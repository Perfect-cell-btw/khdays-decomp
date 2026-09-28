/* Notify param_2 hook, then sweep ctx->items[] (base@+0xc, count@+0x30, stride
 * 0x38): for each element whose +0x14 word is nonzero, call
 * Ov006_InvokeElementCallback(ctx, element, arg). base/count reloaded per-iter (callees
 * may mutate *ctx). */
extern void Ov006_ClearElementList(int ctx, int arg);
extern void Ov006_InvokeElementCallback(int ctx, int element, int arg);
struct Elem3 { unsigned char _pad[0x14]; int field_14; unsigned char _pad2[0x20]; };
struct Ctx3 { unsigned char _0[0xc]; struct Elem3 *items; unsigned char _1[0x20]; int count; };
void Ov006_FlushFlaggedElements(int ctx_, int arg) {
    struct Ctx3 *ctx = (struct Ctx3 *)ctx_;
    int i;
    Ov006_ClearElementList(ctx_, arg);
    for (i = 0; i < ctx->count; i++) {
        if (ctx->items[i].field_14 != 0) {
            Ov006_InvokeElementCallback(ctx_, (int)&ctx->items[i], arg);
        }
    }
}
