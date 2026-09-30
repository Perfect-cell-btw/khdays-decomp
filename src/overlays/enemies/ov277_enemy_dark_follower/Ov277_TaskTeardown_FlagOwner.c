/* Task teardown callback: sets bit 1 of the owning object's +0x5c flags. */

struct Inner {
    char pad[0x5c];
    int flags;
};

struct Mid {
    struct Inner *inner;
};

struct Outer {
    int dummy;
    struct Mid *mid;
};

void Ov277_TaskTeardown_FlagOwner(struct Outer *a) {
    a->mid->inner->flags |= 2;
}
