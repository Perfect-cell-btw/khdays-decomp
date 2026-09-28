extern void Ov028_RC4_Byte(unsigned char *table);
extern unsigned char Ov028_RC4_InitSBox(unsigned int *ctx);

int Ov028_RC4_EncryptInstructions(unsigned int *ctx, unsigned char *src, unsigned char *dst, unsigned int len) {
    unsigned char table[256];
    unsigned int i;
    unsigned char k;
    if ((len & 3) != 0) return -1;
    Ov028_RC4_Byte(table);
    i = 0;
    while (i < len) {
        unsigned char *s = src + i;
        unsigned char *d = dst + i;
        unsigned char t;
        k = Ov028_RC4_InitSBox(ctx);
        t = src[i];
        t ^= k;
        dst[i] = t;
        k = Ov028_RC4_InitSBox(ctx);
        t = s[1];
        t ^= k;
        d[1] = t;
        d[2] = table[s[2]];
        d[3] = s[3];
        i += 4;
    }
    return 0;
}
