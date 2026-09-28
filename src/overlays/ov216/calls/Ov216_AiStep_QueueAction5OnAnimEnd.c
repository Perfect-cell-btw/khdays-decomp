/* Queues action 5 when the animation ends. */

extern int SetIndexedSlot();

struct s1 {
    char *p0;
    char *p1;
};

struct s0 {
    char unk0[4];
    struct s1 *p4;
    char unk8[0x18];
    signed char b20;
};

void Ov216_AiStep_QueueAction5OnAnimEnd(struct s0 *a) {
    struct s1 *r2 = a->p4;
    if (*(unsigned char *)(r2->p1 + 0xad) != 0) {
        return;
    }
    *(unsigned char *)(r2->p0 + 0x1c7) = 5;
    SetIndexedSlot(a, a->b20, 0);
}
