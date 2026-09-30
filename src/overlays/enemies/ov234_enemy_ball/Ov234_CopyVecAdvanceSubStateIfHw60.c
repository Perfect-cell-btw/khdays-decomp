/* AI step: once the actor is active, records its position, queues its stored action and ends the
 * step. */

extern void SetIndexedSlot();

struct hw60 { unsigned short lo : 8, hi : 8; };
struct w3 { int a, b, c; };

void Ov234_CopyVecAdvanceSubStateIfHw60(int this_) {
    int node = *(int *)(this_ + 4);
    int obj = *(int *)node;
    if ((((struct hw60 *)(obj + 0x60))->lo & 1) == 0) return;
    *(struct w3 *)(node + 0x1c) = *(struct w3 *)(obj + 0xb0);
    *(signed char *)(*(int *)node + 0x1c7) = *(signed char *)(*(int *)node + 0x1c9);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
