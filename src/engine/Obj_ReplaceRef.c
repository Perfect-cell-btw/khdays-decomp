struct Obj {
    char pad[0x60];
    unsigned char refcount;
};

void Obj_ReplaceRef(struct Obj **slot, struct Obj *next) {
    struct Obj *old = *slot;
    if (old != 0) {
        if (old->refcount != 0) {
            old->refcount--;
        }
    }
    *slot = next;
    if (next != 0) {
        next->refcount++;
    }
}
