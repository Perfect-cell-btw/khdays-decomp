/* How many ticks of the timeout are left: the configured budget minus the time
 * already spent, both in ticks. The elapsed figure is stored in milliseconds at
 * +0x8d00 and converted with the same (ms * 33514) >> 6 the budget uses; the
 * subtraction is 64-bit, so a negative remainder stays representable. */
extern unsigned long long Ov002_GetTimeoutTicks(void);

typedef struct {
    char pad0000[0x8d00];
    unsigned int nElapsedMs;    /* +0x8d00 */
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

long long Ov002_GetTimeoutRemaining(void) {
    Ov002RootContext *root = data_ov002_0207fa00;

    return Ov002_GetTimeoutTicks()
         - (((unsigned long long)root->nElapsedMs * 33514) >> 6);
}
