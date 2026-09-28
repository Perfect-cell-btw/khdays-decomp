extern void Ov297_AcquireTargetGapAndAngle(int this_);
extern void Ov297_UpdateHeadingVector(int this_);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov297_PrepSubState2IfChildIdle(int this_);

void Ov297_AiPickNextMove(int this_) {
    int node = *(int *)(this_ + 4);

    Ov297_AcquireTargetGapAndAngle(this_);
    Ov297_UpdateHeadingVector(this_);

    if (*(int *)(node + 0x60) >= 4 && *(int *)(node + 0x80) == 0) {
        *(signed char *)(*(int *)node + 0x1c7) = 0xa;
        SetIndexedSlot((void *)this_, *(signed char *)(this_ + 0x20), 0);
        return;
    }
    if (*(int *)(node + 0x7c) >= 4) {
        *(signed char *)(*(int *)node + 0x1c7) = 9;
        SetIndexedSlot((void *)this_, *(signed char *)(this_ + 0x20), 0);
        return;
    }
    SetIndexedSlot((void *)this_, *(signed char *)(this_ + 0x20), (void *)Ov297_PrepSubState2IfChildIdle);
}
