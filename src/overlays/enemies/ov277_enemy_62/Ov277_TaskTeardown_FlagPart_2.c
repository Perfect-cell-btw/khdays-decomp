/* Task teardown callback: sets bit 1 of the flags of the part the task drove. */

struct A { char pad0[4]; int *p; };
struct B { char pad0[4]; struct C *p; };
struct C { char pad[0x5c]; int flag; };

int Ov277_TaskTeardown_FlagPart_2(struct B **arg0) {
    struct C *q = arg0[1]->p;
    return q->flag |= 2;
}
