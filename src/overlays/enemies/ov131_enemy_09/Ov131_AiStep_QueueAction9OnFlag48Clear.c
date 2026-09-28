/* AI step: when the byte behind context +0x48 is clear, pendingAction (+0x1c7) = 9 and the step
 * handler is cleared. */

extern int SetIndexedSlot();

struct Obj {
    char *p0;
    struct Sub *p4;
    char pad[0x20 - 8];
    signed char b20;
};

struct Sub {
    char *s0;
    char pad[0x48 - 4];
    unsigned char *p48;
};

int Ov131_AiStep_QueueAction9OnFlag48Clear(struct Obj *a) {
    struct Sub *s = a->p4;
    if (s->p48[0] != 0)
        return (int)a;
    s->s0[0x1c7] = 9;
    return SetIndexedSlot(a, a->b20, 0);
}
