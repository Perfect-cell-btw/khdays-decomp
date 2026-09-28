extern int SetIndexedSlot();

struct A {
    char pad0[4];
    char **p;
    char pad8[0x18];
    signed char b;
};

int Ov215_AiStep_QueueAction0(struct A *a) {
    (*a->p)[0x1c7] = 0;
    return SetIndexedSlot(a, a->b);
}
