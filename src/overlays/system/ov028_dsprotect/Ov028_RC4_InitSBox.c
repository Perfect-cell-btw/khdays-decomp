/* Returns the next RC4 keystream byte (advancing the state). */

struct Rc4 {
    int i;
    int j;
    unsigned char s[256];
};

int Ov028_RC4_InitSBox(struct Rc4 *ctx) {
    unsigned int i;
    unsigned int j;
    unsigned int si;
    unsigned int sj;

    i = (ctx->i + 1) & 0xff;
    si = ctx->s[i];
    j = (si + ctx->j) & 0xff;
    sj = ctx->s[j];
    ctx->i = i;
    ctx->j = j;
    ctx->s[j] = si;
    ctx->s[i] = sj;
    return ctx->s[(si + sj) & 0xff];
}
