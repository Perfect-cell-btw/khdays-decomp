/* Returns 1 when one of the object's child actors (+0x3ac) is not active (bit 0 of its flags at
 * +0x60 clear), else 0. */

struct Inner {
    char pad[0x60];
    unsigned short field60 : 8;
};

struct Mid {
    char pad[0x3ac];
    struct Inner *p3ac[1];
};

struct Base {
    struct Mid *p0;
};

struct Outer {
    char pad[4];
    struct Base *p4;
};

int Ov167_IsChildInactive(struct Outer *a) {
    struct Base *b = a->p4;
    int i;
    for (i = 0; i < 1; i++) {
        struct Mid *m = b->p0;
        if (!(m->p3ac[i]->field60 & 1)) {
            return 1;
        }
    }
    return 0;
}
