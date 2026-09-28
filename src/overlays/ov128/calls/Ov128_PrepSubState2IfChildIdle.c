extern void Ov128_DecaySpinOverElapsed();
extern void SetIndexedSlot();

void Ov128_PrepSubState2IfChildIdle(int this_) {
    int n = *(int *)(this_ + 4);
    Ov128_DecaySpinOverElapsed(this_);
    if (*(unsigned char *)(*(int *)(n + 4) + 0xad)) return;
    *(char *)(*(int *)n + 0x1c7) = 2;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
