/* Ov245_WaitPartsIdle -- wait for the +0x3c8 owner's three +0x420 parts: once none of them has
 * bit 0 of its +0x60 low byte set, plays pose 2 and moves the node to 020d27b4; while one is
 * still active, counts the state's +0x1c timer up by the scene step and after 1.0 moves to
 * 020d24bc. */
struct hw60 { unsigned short lo : 8, hi : 8; };
struct Ov245Owner { char pad[0x420]; int parts[3]; };

extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_Variant_AiStep_QueueAction0OnAnimEnd(void);
extern void Ov245_Variant_AiVolleyStart(void);

void Ov245_WaitPartsIdle(int *node) {
    int *state = (int *)node[1];
    int i;
    struct Ov245Owner *owner;

    owner = *(struct Ov245Owner **)(*state + 0x3c8);
    for (i = 0; i < 3; i++) {
        if ((((struct hw60 *)(owner->parts[i] + 0x60))->lo & 1) != 0) {
            break;
        }
    }
    if (i >= 3) {
        Ov107_PostTagUpdate(*state, 2, 0);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_Variant_AiStep_QueueAction0OnAnimEnd);
        return;
    }
    state[7] += *(int *)(*node + 0x2c);
    if (state[7] < 0x1000) {
        return;
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_Variant_AiVolleyStart);
}
