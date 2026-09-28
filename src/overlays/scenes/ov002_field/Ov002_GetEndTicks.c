/* Returns the configured end time converted from milliseconds to OS ticks, or 0 when the link flag
 * 2 is not set. */

typedef struct {
    unsigned char pad0000[0x14];
    unsigned int nEndMs;
} Ov002TimingConfig;

extern Ov002TimingConfig *data_ov002_0207fa08;
extern int Ov002_Link_IsFlag2(void);

unsigned long long Ov002_GetEndTicks(void)
{
    Ov002TimingConfig *ctx = data_ov002_0207fa08;

    if (Ov002_Link_IsFlag2() == 0) {
        return 0;
    }

    return ((unsigned long long)ctx->nEndMs * 33514) >> 6;
}
