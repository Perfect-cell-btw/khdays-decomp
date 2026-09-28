/* AI step: once the model's track-0 animation flag (+0xad) is clear, pendingAction (+0x1c7) = 0 and
 * the step handler is cleared. */

extern int SetIndexedSlot();

struct Inner {
    char *p0;
    char *p1;
};

struct Obj {
    char pad0[4];
    struct Inner *inner;
    char pad1[0x20 - 8];
    signed char b20;
};

void Ov254_AiStep_QueueAction0OnAnimEnd(struct Obj *obj) {
    struct Inner *inner = obj->inner;
    if (*(unsigned char *)(inner->p1 + 0xad) != 0) {
        return;
    }
    *(char *)(inner->p0 + 0x1c7) = 0;
    SetIndexedSlot(obj, obj->b20, 0);
}
