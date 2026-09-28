typedef struct {
    unsigned char pad0000[0x10];
    unsigned int nStartMs;
} Ov002TimingConfig;

extern Ov002TimingConfig *data_ov002_0207fa08;
extern int Ov002_Link_IsFlag2(void);

unsigned long long Ov002_GetStartTicks(void)
{
    Ov002TimingConfig *ctx = data_ov002_0207fa08;

    if (Ov002_Link_IsFlag2() == 0) {
        return 0;
    }

    return ((unsigned long long)ctx->nStartMs * 33514) >> 6;
}
