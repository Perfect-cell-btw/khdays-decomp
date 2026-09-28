/* Calls the object's message hook with an empty buffer and message 0x26. */

struct Obj {
    char pad[0x24];
    void (*fn)(struct Obj *, void *, int);
};

struct Buf {
    short a;
    char b;
    char c;
    short rest[17];
};

void Ov268_SendMessage26(struct Obj *obj) {
    struct Buf buf = {0};
    buf.b = 0;
    if (obj->fn != 0) {
        obj->fn(obj, &buf, 0x26);
    }
}
