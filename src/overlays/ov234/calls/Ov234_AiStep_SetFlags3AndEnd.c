extern int SetIndexedSlot();

struct Sub {
    char pad0x1ae[0x1ae];
    unsigned short flags;
};

struct Obj {
    char pad0[4];
    struct Sub **psub;
    char pad8[0x20 - 8];
    signed char b20;
};

int Ov234_AiStep_SetFlags3AndEnd(struct Obj *r0)
{
    (*r0->psub)->flags |= 3;
    return SetIndexedSlot(r0, r0->b20, 0);
}
