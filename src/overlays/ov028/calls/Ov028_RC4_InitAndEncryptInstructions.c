struct Rc4 {
    int i;
    int j;
    unsigned char s[256];
};

extern void Ov028_RC4_Init(struct Rc4 *ctx, unsigned char *key, int keylen);
extern int Ov028_RC4_EncryptInstructions();

int Ov028_RC4_InitAndEncryptInstructions(unsigned char *key, void *a, void *b, int c) {
    struct Rc4 ctx;
    int r;

    Ov028_RC4_Init(&ctx, key, 0x10);
    r = Ov028_RC4_EncryptInstructions(&ctx, a, b, c);
    return (r == -1) ? -1 : 0;
}
