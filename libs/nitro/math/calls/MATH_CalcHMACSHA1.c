/* MATH_CalcHMACSHA1 (NitroSDK): HMAC-SHA1 of `bin` keyed by `key` into `digest`, through the generic
 * keyed-hash driver (func_0200bb80 = MATHi_CalcHMAC) with the SHA-1 context ops
 * (DGT_Hash2Reset init, DGT_Hash2SetSource update, DGT_Hash2GetDigest get-hash). */
typedef unsigned long u32;

typedef struct MATHSHA1Context {
    u32 data[0x68 / 4];
} MATHSHA1Context;

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    void *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

/* the { MATH_SHA1_DIGEST_SIZE, 512 / 8 } initialiser of hash2funcs */
extern const MATHiHMACFuncs data_020418c0;

extern void DGT_Hash2Reset(void *context);
extern void DGT_Hash2SetSource(void *context, const void *input, u32 length);
extern void DGT_Hash2GetDigest(void *context, void *digest);
extern void func_0200bb80(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr,
                          u32 key_len, MATHiHMACFuncs *funcs);

void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len)
{
    MATHSHA1Context context;
    unsigned char hash_buf[20];
    MATHiHMACFuncs hash2funcs = data_020418c0;

    hash2funcs.context = &context;
    hash2funcs.hash_buf = hash_buf;
    hash2funcs.HashReset = (void (*)(void *))DGT_Hash2Reset;
    hash2funcs.HashSetSource = (void (*)(void *, const void *, u32))DGT_Hash2SetSource;
    hash2funcs.HashGetDigest = (void (*)(void *, void *))DGT_Hash2GetDigest;
    func_0200bb80(digest, bin_ptr, bin_len, key_ptr, key_len, &hash2funcs);
}
