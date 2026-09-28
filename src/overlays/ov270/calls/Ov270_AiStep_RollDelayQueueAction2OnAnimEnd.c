extern int RandNextScaled();
extern int SetIndexedSlot();

struct sub {
    int *f0;
    int *f4;
    char gap8[0x2c];
    int f34;
};

struct top {
    char gap0[4];
    struct sub *f4;
    char gap8[0x18];
    signed char b20;
};

void Ov270_AiStep_RollDelayQueueAction2OnAnimEnd(struct top *a) {
    struct sub *s = a->f4;
    int *p;
    int lo, hi, diff;

    if (*(unsigned char *)((char *)s->f4 + 0xad) != 0)
        return;

    p = s->f0;
    lo = p[0x224 / 4];
    hi = p[0x228 / 4];
    diff = hi - lo;
    if (diff < 0)
        diff = -diff;
    diff = diff + 1;
    s->f34 = lo + RandNextScaled(diff);

    *(unsigned char *)((char *)s->f0 + 0x1c7) = 2;

    SetIndexedSlot(a, a->b20, 0);
}
