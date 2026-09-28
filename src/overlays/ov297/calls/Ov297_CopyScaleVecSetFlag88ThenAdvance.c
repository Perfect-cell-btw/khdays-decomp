struct w3 { int a, b, c; };
struct b1_1 { unsigned char pad : 1, b : 1; };
extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void Ov297_AcquireTargetGapAndAngle(int this_);
extern void SetIndexedSlot();

void Ov297_CopyScaleVecSetFlag88ThenAdvance(int this_) {
    int holder = *(int *)(this_ + 4);
    void *src = (void *)(holder + 0x1c);
    *(struct w3 *)(holder + 0x10) = *(struct w3 *)src;
    ScaleVec3Fx12(0xb00, src, src);
    Ov297_AcquireTargetGapAndAngle(this_);
    if (((struct b1_1 *)(*(int *)holder + 0x17a))->b)
        *(int *)(holder + 0x88) = 1;
    if (*(unsigned char *)(*(int *)(holder + 4) + 0xad) != 0) return;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
