/* The configured timeout, in OS ticks. The stored value is milliseconds; the
 * conversion is the NitroSDK one, (ms * 33514) >> 6, kept as a full 64-bit
 * product rather than truncated. */
typedef struct {
    char pad0000[0xc];
    unsigned int nTimeoutMs;    /* +0xc */
} Ov002TimingConfig;

extern Ov002TimingConfig *data_ov002_0207fa08;

unsigned long long Ov002_GetTimeoutTicks(void) {
    return ((unsigned long long)data_ov002_0207fa08->nTimeoutMs * 33514) >> 6;
}
