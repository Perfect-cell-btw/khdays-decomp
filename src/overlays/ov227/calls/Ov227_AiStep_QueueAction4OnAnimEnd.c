extern int SetIndexedSlot();

struct Inner {
    unsigned char *field_0;
    unsigned char *field_4;
};

struct Obj {
    int field_0;
    struct Inner *field_4;
};

void Ov227_AiStep_QueueAction4OnAnimEnd(struct Obj *a) {
    struct Inner *inner = a->field_4;
    if (inner->field_4[0xad] != 0) {
        return;
    }
    inner->field_0[0x1c7] = 4;
    SetIndexedSlot(a, *(signed char *)((char *)a + 0x20), 0);
}
