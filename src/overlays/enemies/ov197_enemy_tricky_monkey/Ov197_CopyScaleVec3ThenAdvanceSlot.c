/* AI step: keeps the previous velocity, damps the current one by 0xb00, and when the model's
 * animation ends queues action 2 and clears the step handler. */

struct w3 { int a, b, c; };
extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void SetIndexedSlot();

void Ov197_CopyScaleVec3ThenAdvanceSlot(int this_) {
    int holder = *(int *)(this_ + 4);
    void *src = (void *)(holder + 0x1c);
    *(struct w3 *)(holder + 0x10) = *(struct w3 *)src;
    ScaleVec3Fx12(0xb00, src, src);
    if (*(unsigned char *)(*(int *)(holder + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)holder + 0x1c7) = 2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
