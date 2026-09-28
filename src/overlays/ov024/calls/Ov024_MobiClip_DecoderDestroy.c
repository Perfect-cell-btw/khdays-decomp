/* The null check really is duplicated in the original (movs r4,r0 + cmpne r4,#0);
 * a single test compiles 4 B short. Keep both halves. */
extern void Ov024_MobiClip_DecoderFreeBuffers_2(int *ctx);
extern void func_ov024_02085104(int *p);

void Ov024_MobiClip_DecoderDestroy(int *ctx) {
    if (ctx != 0 && ctx != 0) {
        Ov024_MobiClip_DecoderFreeBuffers_2(ctx);
        func_ov024_02085104(ctx);
    }
}
