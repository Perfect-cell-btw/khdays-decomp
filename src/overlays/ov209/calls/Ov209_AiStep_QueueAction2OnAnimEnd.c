/* AI step: once the model's track-0 animation flag (+0xad) is clear, pendingAction (+0x1c7) = 2 and
 * the step handler is cleared. */

extern int SetIndexedSlot();

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

struct B {
    unsigned char *p0;
    struct C *c;
};

struct C {
    unsigned char f0[0xad];
    unsigned char fad;
};

void Ov209_AiStep_QueueAction2OnAnimEnd(struct A *a)
{
    struct B *b = a->b;
    if (b->c->fad != 0)
        return;
    b->p0[0x1c7] = 2;
    SetIndexedSlot(a, a->f20, 0);
}
