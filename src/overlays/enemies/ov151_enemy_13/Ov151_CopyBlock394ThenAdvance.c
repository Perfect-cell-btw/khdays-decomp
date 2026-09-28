/* AI step: once the actor is active, copies its stored block (+0x394) into the step, queues action
 * 1 and clears the step handler. */

struct w4 { int a, b, c, d; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot();

void Ov151_CopyBlock394ThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    if ((((struct hw60 *)(*(int *)holder + 0x60))->lo & 1) == 0) return;
    *(struct w4 *)(holder + 0x18) = *(struct w4 *)(*(int *)holder + 0x394);
    *(signed char *)(*(int *)holder + 0x1c7) = 1;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
