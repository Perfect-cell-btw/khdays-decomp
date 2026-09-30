/* AI step: once the actor is active, copies its stored vector into the step, queues action 1 and
 * clears the step handler. */

extern void SetIndexedSlot();

struct hw60 { unsigned short lo : 8, hi : 8; };
struct w3 { int a, b, c; };

void Ov123_CopyVecSetSubState1IfHw60(int this_) {
    int node = *(int *)(this_ + 4);
    int obj = *(int *)node;
    if ((((struct hw60 *)(obj + 0x60))->lo & 1) == 0) return;
    *(struct w3 *)(node + 0x18) = *(struct w3 *)(obj + 0x394);
    *(signed char *)(*(int *)node + 0x1c7) = 1;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
