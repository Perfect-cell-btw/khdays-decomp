/* Calls the object's message hook with an empty buffer and message 0x24. */

struct Buf {
    short a;
    char b;
    char rest[33];
};

struct S {
    char pad[0x24];
    void (*fn)(struct S *, void *, int);
};

void Ov273_SendMessage24_2(struct S *a) {
    struct Buf buf = {0};
    buf.b = 0;
    if (a->fn) {
        a->fn(a, &buf, 0x24);
    }
}
