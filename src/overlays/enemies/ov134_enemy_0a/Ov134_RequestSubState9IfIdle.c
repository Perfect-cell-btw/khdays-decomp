/* Reaction check: requests a fixed sub-state as the pending action (+0x1c7) when no action is
 * pending; returns whether it did. */

struct Inner {
    char field[0x1c8];
};

struct Mid {
    struct Inner *inner;
};

struct Outer {
    char pad[0x214];
    struct Mid *mid;
};

int Ov134_RequestSubState9IfIdle(struct Outer *a) {
    struct Inner *p = a->mid->inner;
    if (p->field[0x1c7] == -1) {
        p->field[0x1c7] = 9;
        return 1;
    }
    return 0;
}
