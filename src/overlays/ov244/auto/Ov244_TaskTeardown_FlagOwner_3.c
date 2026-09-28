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

void Ov244_TaskTeardown_FlagOwner_3(struct Outer *a) {
    a->mid->inner->flags |= 2;
}
