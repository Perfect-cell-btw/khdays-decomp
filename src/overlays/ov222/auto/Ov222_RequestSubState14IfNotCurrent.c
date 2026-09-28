/* Reaction check: queues action 14 unless it is already the current action; returns whether it did.
 */

struct A {
    char pad[0x1c6];
    signed char b1c6;
    signed char b1c7;
};

struct B {
    char pad[0x214];
    struct A **pp;
};

int Ov222_RequestSubState14IfNotCurrent(struct B *x) {
    struct A *a = *x->pp;
    if (a->b1c6 != 14) {
        a->b1c7 = 14;
        return 1;
    }
    return 0;
}
