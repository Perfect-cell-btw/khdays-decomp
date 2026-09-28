extern void Ov181_SwingSweep(int a, int b, int c);
extern int RandNextScaled(int range);
extern void SetIndexedSlot(int *self, int idx, void *cb);

void Ov181_TickWindupThenPickWait(int *self) {
    int *p = (int *)self[0];
    int *s = (int *)self[1];
    int t = s[7] + p[0xb];
    s[7] = t;
    if (t >= 0x555 && t < 0x800 && *(unsigned char *)((char *)s + 0x50) == 0) {
        *(unsigned char *)((char *)s + 0x50) = 1;
        Ov181_SwingSweep((int)s, 0, 1);
    }
    if (*(unsigned char *)s[3] != 0) return;
    {
        int lo = *(int *)(s[0] + 0x224);
        int d = *(int *)(s[0] + 0x228) - lo;
        if (d < 0) d = -d;
        s[0x1d] = lo + RandNextScaled(d + 1);
    }
    *(signed char *)(s[0] + 0x1c7) = 2;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), 0);
}
