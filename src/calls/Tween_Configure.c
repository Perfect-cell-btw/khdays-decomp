/* Zero the Tween, then set nMode, nFrom, nTo and nDuration from the four arguments (in the call's
 * argument order: mode, from, to, duration) and clear flag bits 0, 1 and 2. Callers configure a
 * pair of adjacent Tweens 0x1c apart and start the first -- see Ov000_EmitSplinePair. */

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);

struct X {
    int f_0;
    int f_4;
    int f_8;
    int f_c;
    char _10[8];
    unsigned int flags;
};

void Tween_Configure(struct X *p, int a1, int a2, int a3, int a4) {
    MI_CpuFill8(p, 0, 0x1c);
    p->f_0 = a1;
    p->f_8 = a2;
    p->f_c = a3;
    p->f_4 = a4;
    p->flags &= ~1;
    p->flags &= ~2;
    p->flags &= ~4;
}
