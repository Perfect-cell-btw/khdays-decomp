extern int SetIndexedSlot();

struct Inner {
    unsigned char *ptr0;
    char pad4[0x40];
    unsigned char *ptr44;
};

struct Obj {
    char pad0[4];
    struct Inner *inner;
    char pad8[0x18];
    signed char b20;
};

void Ov142_AiStep_QueueAction2OnFlag44Clear(struct Obj *obj) {
    struct Inner *inner = obj->inner;
    if (inner->ptr44[0] != 0) {
        return;
    }
    inner->ptr0[0x1c7] = 2;
    SetIndexedSlot(obj, obj->b20, 0);
}
