/* If flagged pending, flush the +0x24 block to the target; otherwise (re)register it. Returns 1 unless stale. */
extern void MI_CpuCopy8(void *src, void *dst, int size);
extern int Ov009_CopySourceBlock(int target);
extern void Ov009_Touch_GetLatestValidSample(int self, int target);
struct f2c { unsigned char b0 : 1, b1 : 1, b2 : 1; };
int Ov009_FlushOrRegisterBlock(int param_1, int param_2) {
    struct f2c *fp = (struct f2c *)(param_1 + 0x2c);
    int r = 1;
    if (fp->b1) {
        if (fp->b2 == 0) {
            r = 0;
        } else {
            MI_CpuCopy8((void *)(param_1 + 0x24), (void *)param_2, 8);
            *(unsigned char *)(param_1 + 0x2c) &= ~4;
        }
    } else {
        if (Ov009_CopySourceBlock(param_2) == 0)
            Ov009_Touch_GetLatestValidSample(param_1, param_2);
    }
    return r;
}
