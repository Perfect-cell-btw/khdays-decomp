/* AI step: keeps the previous velocity and damps the current one by 0xb00; when the model's
 * animation ends and the actor touches ground or a wall, queues action 2 and clears the step
 * handler. */

struct w3 { int a, b, c; };
struct b1 { unsigned char b : 1; };
extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void SetIndexedSlot();

void Ov190_CopyScaleVec3GuardedThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    void *src = (void *)(holder + 0x2c);
    *(struct w3 *)(holder + 0x20) = *(struct w3 *)src;
    ScaleVec3Fx12(0xb00, src, src);
    if (*(unsigned char *)(*(int *)(holder + 4) + 0xad) != 0) return;
    {
        int node = *(int *)holder;
        if (((struct b1 *)(node + 0x17a))->b || ((struct b1 *)(node + 0x17c))->b) {
            *(signed char *)(node + 0x1c7) = 2;
            SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
        }
    }
}
