/* Queues action 2 and ends the step. */

extern int SetIndexedSlot();

struct S {
    char pad0[4];
    unsigned char **p4;
    char pad8[0x18];
    signed char b20;
};

int Ov277_AiStep_QueueAction2(struct S *r0) {
    (*r0->p4)[0x1c7] = 2;
    return SetIndexedSlot(r0, r0->b20, 0);
}
