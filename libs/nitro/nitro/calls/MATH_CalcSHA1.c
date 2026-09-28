/* One-shot SHA-1 over a buffer into a 0x68-byte context on the stack. */
extern void DGT_Hash2Reset(void *ctx);
extern void DGT_Hash2SetSource(void *ctx, const void *data, unsigned int len);
extern void DGT_Hash2GetDigest(void *ctx, void *digest);

void MATH_CalcSHA1(void *digest, const void *data, unsigned int len) {
    char ctx[0x68];
    DGT_Hash2Reset(ctx);
    DGT_Hash2SetSource(ctx, data, len);
    DGT_Hash2GetDigest(ctx, digest);
}
